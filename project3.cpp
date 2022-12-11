// DSA 5005 - Computing Structures
// Fall 2022
// Project 3
//Bhavya Reddy Kanuganti
#include <iostream>
#include <string>  // for the string fields
#include <vector>  // to store data
#include <fstream> // to read the csv file

using namespace std;
// class to store one row's information
class DFrow
{
protected:
	// all the fields to store information of a row
	string name;
	char sex;
	int age;
	int height;
	int weight;
	string city;
public:
	DFrow(); // default constructor
	DFrow(string n, char c, int one, int two, int three, string ci); // non-default constructor
	// getters for each of the fields
	string getName();
	char getSex();
	int getAge();
	int getHeight();
	int getWeight();
	string getCity();
	// setters for each of the fields
	void setName(string n);
	void setSex(char c);
	void setAge(int one);
	void setHeight(int two);
	void setWeight(int three);
	void setCity(string ci);
	// display method to display all the fields in the same order
	//  refer to output sample for exact format
	void display();
	// destructor
	~DFrow();
};
//Constructors
DFrow::DFrow() // default constructor
{
	string name = "";
	char sex = 'A';
	int age = 0;
	int height = 0;
	int weight = 0;
	string city = "";
}
DFrow::DFrow(string n, char c, int one, int two, int three, string ci) // non-default constructor
{
	string name = n;
	char sex = c;
	int age = one;
	int height = two;
	int weight = three;
	string city = ci;
}
//Getters
string DFrow::getName()//getter for name
{
	return name;
}
char DFrow::getSex()//getter for sex
{
	return sex;
}
int DFrow::getAge()//getter for age
{
	return age;
}
int DFrow::getHeight()//getter for height
{
	return height;
}
int DFrow::getWeight()//getter for weight
{
	return weight;
}
string DFrow::getCity()//getter for city
{
	return city;
}
//Setters
void DFrow::setName(string n)//setter for name
{
	name = n;
}
void DFrow::setSex(char c)//setter for sex
{
	sex = c;
}
void DFrow::setAge(int one)//setter for age
{
	age = one;
}
void DFrow::setHeight(int two)//setter for height
{
	height = two;
}
void DFrow::setWeight(int three)//setter for weight
{
	weight = three;
}
void DFrow::setCity(string ci)//setter for city
{
	city = ci;
}
void DFrow::display()//display rows
{
	cout << getName() << " " << getSex() << " " << getAge() << " " << getHeight() << " " << getWeight() << " " << getCity() << endl;
}
//Destructor
DFrow::~DFrow()
{
	string name = "";
	char sex = 'A';
	int age = 0;
	int height = 0;
	int weight = 0;
	string city = "";
}
// class to store the entire dataframe
class DataFrame
{
protected:
	vector<DFrow> data; // field storeing all the data
	vector<string> headers; // field to only the headers
	int nRows, nCols; // store the number of rows and cols
public:
	// Constructors
	DataFrame();
	DataFrame(int rows, int cols);
	// Overload the [] operator to access data in DF
	DFrow operator[](int i);
	// File reading Method
	void readCSV(string filename, string headerPresence);
	// Output Method
	void display();
	// Search Record
	DFrow searchRecord(string name);
	// Setters
	void setColName(int col, char* name); // change the name of a header/column
	// Getters
	int getNumberRows();                                              // returns the number of rows
	int getNumberCols();                                              // returns the number of columns
	//DataFrame* getColumns(int* columns, int cLen);                    // returns a dataframe with a set of cLen number of columns
	DataFrame* getRows(int* rows, int rLen);                          // returns a data frame with a set of rLen number of rows
	//DataFrame* getRowsCols(int* rows, int rLen, int* cols, int cLen); // returns a data frame given a set of row numbersand column numbers
	string getHeader(int i);                                          // returns the header name given a index position
	int colindex(string head);
	// Find info of a given column
	double findAverage(int colNumber); // returns the average of the given column
	double findMax(int colNumber);     // returns the max of the given column
	double findMin(int colNumber);     // returns the min of the given column
	double frequency(int colNumber);   // displays the frequency of the unique values
	// Destructor
	~DataFrame();
};
// Constructors
DataFrame::DataFrame()//Default constructor
{
	nRows = 0;
	nCols = 0;
}

DataFrame::DataFrame(int rows, int cols)//non-default constructor
{
	nRows = rows;
	nCols = cols;
}
DFrow DataFrame::operator[](int i)// Overload the [] operator to access data in DF
{
	return data[i];
}
void DataFrame::readCSV(string filename, string headerPresence)//file reading method
{
	string str1, str2, str3, str4, str5, str6;
	ifstream fin;
	fin.open(filename, ios_base::in);//opening the file
	if (headerPresence == "true")//Checking if header is present or not
	{//getting all the headers and pushing it to headers
		getline(fin, str1, ',');
		headers.push_back(str1);
		getline(fin, str2, ',');
		headers.push_back(str2);
		getline(fin, str3, ',');
		headers.push_back(str3);
		getline(fin, str4, ',');
		headers.push_back(str4);
		getline(fin, str5, ',');
		headers.push_back(str5);
		getline(fin, str6);
		headers.push_back(str6);
	}
	//int strAge = stoi(str3);
	//int strHeight = stoi(str4);
	//int strWeight = stoi(str5);
	//char strSex[1];
	//for (int i = 0; i < sizeof(strSex); i++)
	//{
		//strSex[i] = str2[i];
	//}
	
	for (int i = 0; i < nRows; i++)
	{//getting the rows and pushing into temprow
		DFrow temprow;
		getline(fin, str1, ',');
		temprow.setName(str1);
		getline(fin, str2, ',');
		temprow.setSex(str2[0]);
		getline(fin, str3, ',');
		temprow.setAge(stoi(str3));
		getline(fin, str4, ',');
		temprow.setHeight(stoi(str4));
		getline(fin, str5, ',');
		temprow.setWeight(stoi(str5));
		getline(fin, str6);
		temprow.setCity(str6);
		data.push_back(temprow);
	}
}
void DataFrame::display()//displaying the data frame
{
	cout << " ";
	for (int i = 0; i < nCols-1; i++)
	{
		cout << headers[i] << " ";
	}
	cout << headers[nCols-1]<< endl;
	for (int i = 0; i < nRows; i++)
	{
		data[i].display();
	}

}
class ExceptionRecord {};//Exception handling for search record
DFrow DataFrame::searchRecord(string name)//searching if a record is present or not
{
	
		for (int i = 0; i < nRows; i++)
		{
			try {
			if (data[i].getName() != name)throw ExceptionRecord();//if the name is not found then exception is thrown
			
			else
			{
				cout << "Record found:" << endl << "	";
				cout << data[i].getName() << " ";
				cout << data[i].getSex() << " ";
				cout << data[i].getAge() << " ";
				cout << data[i].getHeight() << " ";
				cout << data[i].getWeight() << " ";
				cout << data[i].getCity() << " " << endl;
				return data[i];
			}
		}
		catch (ExceptionRecord myException)//Handling exception
		{
			//cout << "Record not found";comes out of loop
		}
	}
		//else
		cout << "Record not found" << endl;//After the record not being found
}
void DataFrame::setColName(int col, char* name)//setting the column name
{
	headers[col] = name;
}
int DataFrame::getNumberRows()//getter for number of total rows
{
	return nRows;
}
int DataFrame::getNumberCols()//getter for number of total columns
{
	return nCols;
}

DataFrame* DataFrame::getRows(int* rows, int rLen)//function to get particular rows in dataframe
{
	DataFrame* temp;
	temp = new DataFrame(rLen, nCols);
	for (int i = 0; i < rLen; i++)
	{
		data[rows[i]].display();
	}

	return temp;
}
string DataFrame::getHeader(int i)//getter for headers
{
	string h;
	h = headers[i];
	return h;
}
int DataFrame::colindex(string head)//getter for column number of header
{
	for (int i = 0; i < nCols; i++)
	{
		if (headers[i] == head)
		{
			return i;
		}
	}
}
double DataFrame::findAverage(int colNumber)//finding the average of given column
{

	double avg=0;
	for (int i = 0; i < nRows; i++)
	{
		/*if (colNumber == 0)
		{
			//cout << "Average for Name cannot be found since it is nan" << endl;
			break;
		}
		else if (colNumber == 1)
		{ 
			//cout << "Average for Sex cannot be found since it is nan" << endl;
			break;
		}*/
		if (colNumber == 2)
			avg = avg + data[i].getAge();//we get the sum of all elements here
		else if (colNumber == 3)
			avg = avg + data[i].getHeight();
		else if (colNumber == 4)
			avg = avg + data[i].getWeight();
		/*else if (colNumber == 5)
		{
			//cout << "Average for City cannot be found since it is nan" << endl;
		break;
		}*/
	}
	avg /= nRows;//dividing with total number of rows  to get average
	avg = int(avg);//converting to int
	return avg;
}
double DataFrame::findMax(int colNumber)//finding the highest value in the column
{
	double max = 0;
	for (int i = 0; i < nRows; i++)//looping through the entire row
	{
		if (colNumber == 0)
		{
			cout << "Maximum for Name cannot be found since it is nan" << endl;//since name is categorical
			break;
		}
		else if (colNumber == 1)
		{ 
			cout << "Maximum for Sex cannot be found since it is nan" << endl;//since sex is categorical
			break;
		}
		else if (colNumber == 2)
		{
			int temp;
			temp = data[i].getAge();//getting the age row and finding the max value
			if (temp > max)
				max = temp;

		}
		else if (colNumber == 3)
		{
			int temp;
			temp = data[i].getHeight();//getting the height row and finding the max value
			if (temp > max)
				max = temp;
		
		}
		else if (colNumber == 4)
		{
			int temp;
			temp = data[i].getWeight();//getting the weight row and finding the max value
			if (temp > max)
				max = temp;
			
		}
		else if (colNumber == 5)
		{ 
			cout << "Maximum for City cannot be found since it is nan" << endl;//since city is categorical
			cout << endl;
			break;
		}
		
	}
	return max;// returning the max values
}
double DataFrame::findMin(int colNumber)
{
	double min = 1000;
	for (int i = 0; i < nRows; i++)
	{
		if (colNumber == 0)
		{ 
			cout << "Minimum for Name cannot be found since it is nan" << endl;//since name is categorical
			break;
		}
		else if (colNumber == 1)
		{ 
			cout << "Minimum for Sex cannot be found since it is nan" << endl;//since sex is categorical
			break;
		}
		else if (colNumber == 2)
		{
			int temp;
			temp = data[i].getAge();//getting the age row and finding the min value
			if (temp < min)
				min = temp;
			//return min;
		}
		else if (colNumber == 3)
		{
			int temp;
			temp = data[i].getHeight();//getting the height row and finding the min value
			if (temp < min)
				min = temp;
			//return min;
		}
		else if (colNumber == 4)
		{
			int temp;
			temp = data[i].getWeight();//getting the weight row and finding the min value
			if (temp > min)
				min = temp;
			//return min;
		}
		else if (colNumber == 5)
		{
			cout << "Maximum for City cannot be found since it is nan" << endl;//since city is categorical
		}
	}
	return min;
}
double DataFrame::frequency(int colNumber)//Checking the number of occurences of each element in a row
{
	string* uniqueElements = new string[nRows];//stores unique elements
	int* count = new int[nRows];//counts unique elements
	string elem;//string to store elements
	bool el;//boolean to check if element is there or not
	int row = 0;
	if (colNumber == 0)//Checking if the gven column is names
	{
		for (int i = 0; i < nRows; i++)//looping to check matching elements
		{
			elem = data[i].getName();//taking a name
			el = false;//el<-false
			for (int j = 0; j < row; j++)//looping to check if elements match
			{
				if (uniqueElements[j] == elem)//checking if elements matches
				{
					count[j]++;//counting elements
					el = true;// el<- true if element is present
				}
			}
			if (el == false)// if the elements doesn't match
			{
				uniqueElements[row] = elem;
				count[row] = 1;
				row++;
			}
		}
	}
	if (colNumber == 1)//Checking if the gven column is sex
	{
		for (int i = 0; i < nRows; i++)//looping to check matching elements
		{

			elem = data[i].getSex();//taking element from row
			el = false;
			for (int j = 0; j < row; j++)//looping to check if elements match
			{
				if (uniqueElements[j] == elem)//checking if elements matches
				{
					count[j]++;//counting elements
					el = true;// el<- true if element is present
				}
			}
			if (el == false)// if the elements doesn't match
			{
				uniqueElements[row] = elem;
				count[row] = 1;//counting elements
				row++;
			}
		}
	}
	if (colNumber == 5)//Checking if the gven column is city
	{
		for (int i = 0; i < nRows; i++)//looping to check matching elements
		{

			elem = data[i].getCity();//taking element from row
			el = false;
			for (int j = 0; j < row; j++)//looping to check if elements match
			{
				if (uniqueElements[j] == elem)//checking if elements matches
				{
					count[j]++;//counting elements
					el = true;// el < -true if element is present
				}
			}
			if (el == false)// if the elements doesn't match
			{
				uniqueElements[row] = elem;
				count[row] = 1;//counting elements
				row++;
			}
		}
	}
	if (colNumber == 2|| colNumber == 3 || colNumber == 4)//Numeric Variables 
		cout << "Maximum for City cannot be found"<<endl;
	for (int i = 0; i < row; i++)//Displays the unique elements and it's count
	{
		cout << uniqueElements[i] << ":" << count[i] << endl;
	}
	return 1;
}
DataFrame::~DataFrame()//Destructor
{
	nRows = 0;
	nCols = 0;
}
// main function

int main()
{
	int numRows, numCols;//number of rows and columns
	string fileName;//Name of the csv file
	string headerBool;//to check if header is present or not
	int a, b,rcount;
	char command;
	cin >> numRows >> numCols >> headerBool >> fileName;//taking the input
	DataFrame* d = new DataFrame(numRows, numCols);
	d->readCSV(fileName, headerBool); // use this method to read in the data from the csv file
		// TODO: read the commands from the input file (redirected input)
	string Name;
	string colHead;
	int c=0;

	while (cin >> command)
	{
		switch (command)
		{
		case 'F'://Case to search records
			cin >> Name;
			d->searchRecord(Name);//function call
			cout << endl;

			break;

		case 'D'://Display the dataframe
			d->display();//Function call
			cout << endl;
			break;
		case 'A'://Average of column
			cin >> colHead;//input column name
			c=d->colindex(colHead);//function call to find the column number
			if (c == 2||c==3||c==4)//Average for numeric variables
				cout << "Average of " << colHead << " is " << d->findAverage(c);
			else//categoricsl variables don't have average
				cout << "Average for " << colHead << " cannot be found since it is nan";
			cout << endl;
			break;
		case 'Q'://Number of occurences in a row
			cin >> colHead;//input column name
			c = d->colindex(colHead);//function call to find the column number
			d->frequency(c);//Funvtion call for frequency
			break;
		case 'X'://Max value in row
			cin >> colHead;//input column name
			c = d->colindex(colHead);//function call to find the column number
			if (c == 2 || c == 3 || c == 4)//Max of Numeric columns
				cout << "Max of " << colHead << " is " << d->findMax(c);
			else//categorical columns don;t have max value
				cout << "Max for " << colHead << " cannot be found since it is nan";
			cout << endl;
			break;
		case 'I'://Min value in row
			cin >> colHead;//input column name
			c = d->colindex(colHead);//function call to find the column number
			if (c == 2 || c == 3 || c == 4)//Min of Numeric columns
				cout << "Min of " << colHead << " is " << d->findMin(c);
			else//categorical columns don;t have min value
				cout << "Min for " << colHead << " cannot be found since it is nan";
			cout << endl;
			break;
		case 'R':
			cin >> a;//input starting row
			cin >> b;//input ending row
			rcount = b - a;//Size of subset
			int* r;//pointer for rows
			r = new int[rcount];
			for (int i = 0; i < rcount; i++)//setting the row numbers for subset
			{
				r[i] = a;
				a++;
			}
			DataFrame* subset;//Subset dataframe
			subset = new DataFrame(rcount , numCols);
			cout << endl;
			subset = d->getRows(r, rcount);//function call for getting rows
			break;
		deafult:cout << "Command not found" << endl;//default case
		}
	}
		return 0;
}