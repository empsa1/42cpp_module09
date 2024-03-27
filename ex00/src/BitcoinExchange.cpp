#include "../includes/BitcoinExchange.hpp"

int search(const std::string &string, char a)
{
    int i = -1;
    int counter = 0;
    while (string.c_str()[++i] != '\0')
    {
        if (string.c_str()[i] == a)
            counter++;
    }
    return counter;
}

BitcoinExchange::BitcoinExchange()
{
    if (DEBUG_MODE == 1)
        std::cout << CYAN << DEFAULT_CONSTRUCTOR << RESET << std::endl;
}

int BitcoinExchange::toInt(std::string &string) {
    std::istringstream iss(string);
    int result;
    if (!(iss >> result)) {
        return -1;
    }
    if (std::abs(result) == __INT_MAX__)
        throw (std::out_of_range(OUT_OF_BOUNDS));
    return result;
}

double BitcoinExchange::toDouble(std::string &string) {
    std::istringstream iss(string);
    double result;
    if (!(iss >> result)) {
        return -1;
    }
    if (std::abs(result) == __DBL_MAX__)
        throw (std::out_of_range(OUT_OF_BOUNDS));
    return result;
}

bool BitcoinExchange::isDouble(const std::string &str)
{
    return (str.find_first_not_of(DOUBLE_ARRAY) == std::string::npos && str.find(".") != std::string::npos
		&& (str.find("-") == 0 || str.find("-") == std::string::npos));
}

bool BitcoinExchange::isInt(const std::string &str)
{
    return str.find_first_not_of(INT_ARRAY) == std::string::npos && ((str.find("-") == 0 && str.length() > 1 ) || str.find("-") == std::string::npos);
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int year, int month) {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month - 1];
}

int calculateDateDifference(const std::string& date, const std::string& entryDate)
{
    std::istringstream spliter(date);
    std::istringstream spliter2(entryDate);
    std::string temp;
    int year1, month1, day1;
    int year2, month2, day2;

    std::getline(spliter, temp , '-');
    year1 = BitcoinExchange::toInt(temp);
    std::getline(spliter, temp , '-');
    month1 = BitcoinExchange::toInt(temp);
    std::getline(spliter, temp , '-');
    day1 = BitcoinExchange::toInt(temp);

    std::getline(spliter2, temp , '-');
    year2 = BitcoinExchange::toInt(temp);
    std::getline(spliter2, temp , '-');
    month2 = BitcoinExchange::toInt(temp);
    std::getline(spliter2, temp , '-');
    day2 = BitcoinExchange::toInt(temp);
    int daysDif = 0;
    if (year1 < year2)
    {
        return -1;
    }
    else if (year1 > year2)
    {
        while (year1 > year2)
        {
            daysDif += daysInMonth(year2, month2);
            month2++;
            if (month2 > 12)
            {
                year2++;
                month2 = 1;
            }
        }
        if (month1 < month2)
        {
            while (month1 <= month2)
            {
                daysDif += daysInMonth(year1, month1);
                month1++;
            }
        }
        else if (month1 > month2)
        {
            while (month2 <= month1)
            {
                daysDif += daysInMonth(year1, month1);
                month2++;
            }
        }
        return (daysDif += std::abs(day1 - day2));
    }
    else if (year1 == year2)
    {
        if (month1 < month2)
        {
            return -1;
        }
        else if (month1 > month2)
        {
            int daysDif = 0;
            while (month2 <= month1)
            {
                daysDif += daysInMonth(year1, month1);
                month2++;
            }
        }
        else if (month1 == month2)
        {
            if (day1 > day2)
            {
                return (daysDif += std::abs(day1 - day2));
            }
            else if (day1 == day2)
            {
                return (daysDif += std::abs(day1 - day2));
            }
            else
            {
                return -1;
            }
        }
    }
    else if (day1 > day2)
        return (daysDif += std::abs(day1 - day2));
    return -1;
}

bool isValidNumber(std::string value)
{
    int number = 0;
    if (!BitcoinExchange::isDouble(value) && !BitcoinExchange::isInt(value))
        return false;
    if (BitcoinExchange::isDouble(value))
    {
        number = BitcoinExchange::toDouble(value);
        if (number < 0.00 || number > 1000.00)
        return false;
    }
    else if (BitcoinExchange::isInt(value))
    {
        number = BitcoinExchange::toInt(value);
        if (number < 0 || number > 1000)
            return false;
    }
    return true;
}

bool isValidDate(const std::string& date) {
    int year = 0;
    int month = 0;
    int day = 0;

    time_t currentTime = time(NULL);
    tm* localTime = localtime(&currentTime);
    int currentYear = localTime->tm_year + MIN_YEAR;
    int currentMonth = localTime->tm_mon + 1;
    int currentDay = localTime->tm_mday;
    if (search(date, '-') != 2 || date.size() != 10)
        return false;

    std::istringstream spliter(date);
    std::string temp;

    std::getline(spliter, temp , '-');
    if (temp.size() != 4 || !BitcoinExchange::isInt(temp))
        return false;
    year = BitcoinExchange::toInt(temp);
    if (year < MIN_YEAR || year > currentYear)
        return false;
    std::getline(spliter, temp , '-');
    if (temp.size() != 2 || !BitcoinExchange::isInt(temp))
        return false;
    month = BitcoinExchange::toInt(temp);
    if (month < 1 || month > 12 || (year == currentYear && month > currentMonth))
        return false;

    std::getline(spliter, temp , '-');
    if (temp.size() != 2 || !BitcoinExchange::isInt(temp))
        return false;
    day = BitcoinExchange::toInt(temp);
    if (day < 1)
        return false;

    static const int daysInMonth[] = {31, 28 + (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (day > daysInMonth[month - 1])
        return false;

    if (year == currentYear && month == currentMonth && day > currentDay)
        return false;

    return true;
}

std::list<std::string> convertDbToList()
{
    std::ifstream file(database);
    int flag = 0;
    if(file.is_open())
    {
        std::ifstream file(database);
        std::list<std::string> content;
        std::string line;
        while (std::getline(file, line))
        {
            flag = 1;
            content.push_back(line);
        }
        file.close();
        if (flag == 0)
            throw DatabaseEmptyException();
        return content;
    }
    throw CouldNotOpenFileException();
}

void find_exchange(const std::string& date, double value, const std::list<std::string>& db)
{
    int closestDifference = std::numeric_limits<int>::max();
    std::string closestDate;
    double closestNumberDB = 0.0;

    std::list<std::string>::const_iterator iter = db.begin();
    std::list<std::string>::const_iterator iter2 = db.end();
    while (++iter != iter2)
    {
        const std::string& entry = *iter;
        size_t pos = entry.find(',');
        if (pos != std::string::npos)
        {
            std::string db_date = entry.substr(0, pos);
            int difference = calculateDateDifference(date, db_date);
            if (difference >= 0 && difference < closestDifference)
            {
                closestDifference = difference;
                closestDate = db_date;
                std::string db_value_str = entry.substr(pos + 1);
                closestNumberDB = BitcoinExchange::toDouble(db_value_str);
            }
        }
    }
    if (!closestDate.empty())
    {
        // std::cout << YELLOW << "Closest Date: " << closestDate << RESET << std::endl;
        double exchangedValue = closestNumberDB * value;
        std::cout << GREEN << date << " => " << value << " = " << exchangedValue << RESET << std::endl;
    }
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
    if (this != &other)
        this->filename = other.filename;
    return (*this);
}

BitcoinExchange::BitcoinExchange(char *filename) : filename(filename)
{
    if (DEBUG_MODE == 1)
        std::cout << CYAN << PARAMTER_CONSTRUCTOR << RESET << std::endl;
    std::list<std::string> db = convertDbToList();
    std::ifstream file(filename);
    int flag = 0;
    if(file.is_open())
    {
        std::list<std::string> content;
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            flag = 1;
            size_t pos = line.find('|');
            if (pos != std::string::npos)
            {
                std::string date = line.substr(0, pos);
                std::string value = line.substr(pos + 1);
                date.erase(0, date.find_first_not_of(" \t"));
                date.erase(date.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);  
                if (isValidDate(date) && isValidNumber(value))
                    find_exchange(date, BitcoinExchange::toDouble(value), db);
                else
                {
                    std::cout << RED << "Error: Format in line: " << line << RESET << std::endl;
                }
            }
            else
            {
                std::cout << RED << "Error: Missing '|' in line: " << line << RESET << std::endl;
            }
        }
        file.close();
        if (flag == 0)
            std::cout << RED << "Error: Input File is empty!" << line << RESET << std::endl;
    }
    else
        throw CouldNotOpenFileException();
}

BitcoinExchange::~BitcoinExchange()
{
    if (DEBUG_MODE == 1)
        std::cout << CYAN << DESTRUCTOR << RESET << std::endl;
}