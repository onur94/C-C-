#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

std::map<std::string, int> month_names = {{"Jan", 1},
										  {"Feb", 2},
										  {"Mar", 3},
										  {"Apr", 4},
										  {"May", 5},
										  {"Jun", 6},
										  {"Jul", 7},
										  {"Aug", 8},
										  {"Sep", 9},
										  {"Oct", 10},
										  {"Nov", 11},
									      {"Dec", 12}};

typedef struct {
	int day;
	int month;
	int year;
} ST_DATE;

typedef struct {
	int hour;
	int minute;
	int second;
} ST_TIME;

void adv_tokenizer(string s, char del, vector<string> *splittedData)
{
    stringstream ss(s);
    string word;
    while (!ss.eof()) {
        getline(ss, word, del);
        splittedData->push_back(word);
    }
}

void parseDate(const char *date)
{
	ST_DATE stDate;
	vector<string> splittedData;
	adv_tokenizer(date, ' ', &splittedData);
	stDate.month = month_names[splittedData[0]];
	stDate.day = stoi(splittedData[1]);
	stDate.year = stoi(splittedData[2]);
	cout << stDate.day << "/" << stDate.month << "/" << stDate.year << endl;
}

void parseTime(const char *time)
{
	ST_TIME stTime;
	vector<string> splittedData;
	adv_tokenizer(time, ':', &splittedData);
	stTime.hour = stoi(splittedData[0]);
	stTime.minute = stoi(splittedData[1]);
	stTime.second = stoi(splittedData[2]);
	cout << stTime.hour << ":" << stTime.minute << ":" << stTime.second << endl;
}

int main(int argc, char const* argv[])
{
	parseDate(__DATE__);
	parseTime(__TIME__);
    return 0;
}
