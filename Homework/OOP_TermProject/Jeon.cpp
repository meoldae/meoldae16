#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>	
#define PAGE 20		
using namespace std;

int fileOpen(vector<string>* page) {
	ifstream file;
	string line;
	file.open("test.txt");

	if (!file.is_open())
	{
		cout << "파일을 찾을 수 없음" << endl;
		return 0;
	}
	else {
		while (getline(file, line, '\n')){
			char* buffer = new char[10000];

			strcpy(buffer, line.c_str());

			char* tok = strtok(buffer, " ");
			while (tok != NULL) {
				page->push_back(string(tok));
				tok = strtok(NULL, " ");
			}
		}
		file.close();
		return 1;
	}
}

int getWordIndexOfLine(vector<string> page, int lineNum) {

	if (lineNum <= 1)
		return 0;

	int i = 0, lineCnt = 1, size = page.size();
	string line;

	while (1) {
		line = "";
		while (1) { 

			if (i == size) {
				return size;
			}

			if (line.length() + page[i].length() > 75) {
				lineCnt++;
				break;
			}

			line += (page[i] + " "); 
			i++;
		}
		if (lineCnt == lineNum)
			return i;
	}
}

void setlastLineNum(vector<string> page, int* lastLineNum) {
	
	int i, check;
	i = *lastLineNum;
	while (1) {
		check = getWordIndexOfLine(page, i);
		if (check == page.size()) { 
			*lastLineNum = i;
			break;
		}
		else
			i++;
	}
}

void printPage(vector<string> page, int* currentLineNum, int lastLineNum) {

	int cnt = 0, wordNum, end;
	string line;

	if (*currentLineNum + PAGE > lastLineNum) 	
		*currentLineNum = lastLineNum - PAGE;

	wordNum = getWordIndexOfLine(page, *currentLineNum);
	end = getWordIndexOfLine(page, *currentLineNum + PAGE + 1);

	for (int i = *currentLineNum; i < *currentLineNum + PAGE; i++) { 
		if (i >= lastLineNum) 
			return;

		line = "";

		while (1) {	

			if (wordNum == end) {	
				break;
			}
			if (line.length() + page[wordNum].length() > 75)
				break;

			line += (page[wordNum] + " ");
			wordNum++;
		}
		
		cout << setw(2) << right << i << "| ";	
		cout << line << endl;			
	}
}

void printConsoleMsg(char consoleMsgCode) {

	if (consoleMsgCode == 'e') {
		cout << "잘못된 입력입니다";
	}
	else if (consoleMsgCode == 'c') {
		cout << "해당 단어가 없습니다.";
	}
	else if (consoleMsgCode == 'd') {
		cout << "(콘솔메시지)";
	}
	else if (consoleMsgCode == 'm') {
		cout << "마지막 페이지입니다";
	}
	else if (consoleMsgCode == 'n') {
		cout << "첫 페이지입니다";
	}
	else if (consoleMsgCode == 's') {
		cout << "명령 수행 완료";
	}

	cout << endl;
}

bool is_digit(char str[]) {

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}

int insert(vector<string>* page, int lineNum, int wordNum, string word) {

	int wordIndex = getWordIndexOfLine(*page, lineNum);
	int nextWordIndex = getWordIndexOfLine(*page, lineNum + 1);

	if (nextWordIndex - wordIndex < wordNum)
		return 0; 

	page->insert(page->begin() + (wordIndex + wordNum), word); 
	return 1;
}

int _delete(vector<string>* page, int lineNum, int wordNum) {
	
	int wordIndex = getWordIndexOfLine(*page, lineNum);
	int nextWordIndex = getWordIndexOfLine(*page, lineNum + 1);

	if (nextWordIndex - wordIndex < wordNum)
		return 0; 

	page->erase(page->begin() + (wordIndex + wordNum)); 
	return 1;
}

void edit(vector<string>* page, string originalWord, string replaceWord) {
	int size = page->size();

	for (int i = 0; i < size; i++) {
		if (page->at(i) == originalWord)
			page->at(i) = replaceWord;
	}
}

int getLineNum(vector<string> page, int wordNum) {

	int i = 0, lineCnt = 1, size = page.size();
	string line;

	for (int i = 0; i < wordNum;) {
		line = "";
		while (1) {

			if (line.length() + page[i].length() > 75) {
				lineCnt++;
				break;
			}

			line += (page[i] + " "); 

			if (page[i] == page[wordNum])	
				break;						

			i++;
		}
	}
	return lineCnt;
}

int search(vector<string> page, string keyword) {
	int size = page.size();

	for (int i = 0; i < size; i++) {
		if (page.at(i) == keyword)
			return getLineNum(page, i);
	}
	return 0;
}

void saveFile(vector<string> page) {
	ofstream file;
	file.open("test.txt");

	int size = page.size();

	string line;

	for(int i = 0; i < size; i++) {
		file << page[i] + " ";
	}

	file.close();
	cout << endl <<"저장 완료" << endl;
	exit(0);
}

int main() {

	vector<string> page;

	if (!fileOpen(&page))
		exit(0);

	int currentLineNum = 1, lastLineNum = 0;
	char consoleMsgCode = 'd';

	string command, strPara1, strPara2;
	int intPara1, intPara2;

	while (1) {

		setlastLineNum(page, &lastLineNum);
		printPage(page, &currentLineNum, lastLineNum);

		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "n:다음페이지, p:이전페이지, i:삽입, d:삭제, c:변경, s:찾기, t:저장후종료" << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		printConsoleMsg(consoleMsgCode);
		cout << "-------------------------------------------------------------------------------" << endl;
		cout << "입력 : ";
		cin >> command;


		if (command == "n") {
			if (currentLineNum + PAGE == lastLineNum) {
				consoleMsgCode = 'm';
			}
			else {
				currentLineNum += PAGE;
				if (currentLineNum > lastLineNum)
					currentLineNum = lastLineNum;
				consoleMsgCode = 'd';
			}
		}
		else if (command == "p") {
			if (currentLineNum == 1) {
				consoleMsgCode = 'n';
			}
			else {
				currentLineNum -= PAGE;
				if (currentLineNum < 1)
					currentLineNum = 1;
				consoleMsgCode = 'd';
			}
		}
		else if (command[0] == 'i') {
			if ((command[1] == '(' && command[command.length() - 1] == ')') &&
				command.length() > 7) {

				command.erase(0, 2);

				char* buffer = new char[75];
				strcpy(buffer, command.c_str());
				char* tok = strtok(buffer, ",");

				if (is_digit(tok)) {
					intPara1 = atoi(tok);
					int biggerOne = currentLineNum + PAGE - 1;

					if (biggerOne < lastLineNum) {
						if (intPara1 >= currentLineNum && intPara1 <= biggerOne) {
							tok = strtok(NULL, ",");

							if (is_digit(tok)) {
								intPara2 = atoi(tok);
								tok = strtok(NULL, ")");
								strPara1 = string(tok);

								if (insert(&page, intPara1, intPara2, strPara1)) {
									consoleMsgCode = 's';
									system("cls");
									continue;
								}
							}
						}
					}
				}

			}
			consoleMsgCode = 'e';
		}
		else if (command[0] == 'd') {
			if ((command[1] == '(' && command[command.length() - 1] == ')') &&
				command.length() > 5) {

				command.erase(0, 2);

				char* buffer = new char[75];
				strcpy(buffer, command.c_str());
				char* tok = strtok(buffer, ",");

				if (is_digit(tok)) {
					intPara1 = atoi(tok);

					int biggerOne = currentLineNum + PAGE - 1;
					if (biggerOne < lastLineNum) {
						if (intPara1 >= currentLineNum && intPara1 <= biggerOne) {
							tok = strtok(NULL, ")");

							if (is_digit(tok)) {
								intPara2 = atoi(tok);

								if (_delete(&page, intPara1, intPara2)) {
									consoleMsgCode = 's';
									system("cls");
									continue;
								}
							}
						}
					}
				}
			}
			consoleMsgCode = 'e';
		}
		else if (command[0] == 'c') {
			if ((command[1] == '(' && command[command.length() - 1] == ')') &&
				command.length() > 5) {

				command.erase(0, 2);

				char* buffer = new char[75];
				strcpy(buffer, command.c_str());

				char* tok = strtok(buffer, ",");
				strPara1 = string(tok);
				tok = strtok(NULL, ")");
				strPara2 = string(tok);

				edit(&page, strPara1, strPara2);
				consoleMsgCode = 's';
			}
			else
				consoleMsgCode = 'e';
		}
		else if (command[0] == 's') {
			if ((command[1] == '(' && command[command.length() - 1] == ')') &&
				command.length() > 3) {

				command.erase(0, 2);

				char* buffer = new char[75];
				strcpy(buffer, command.c_str());

				char* tok = strtok(buffer, ")");
				strPara1 = string(tok);

				int check = search(page, strPara1);
				if (check) {
					currentLineNum = check;
					consoleMsgCode = 's';
				}
				else {
					consoleMsgCode = 'c';
				}
			}
			else
				consoleMsgCode = 'e';
		}
		else if (command == "t") {
			saveFile(page);
		}
		else
			consoleMsgCode = 'e';
		system("cls");
	}
}