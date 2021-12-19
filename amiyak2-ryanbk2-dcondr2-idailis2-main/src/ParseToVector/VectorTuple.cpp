#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>

#include "VectorTuple.h"

using namespace std;

//receives the individual parameters from a line of the text file, and creates a tuple
tuple <string,int,string,string> createTuple(string name, int weight, string edge1, string edge2)
{
  tuple <string, int, string, string> tup;
  tup = make_tuple(name, weight, edge1, edge2);
  return tup;
}

//receives the entire line and breaks it up into three strings and an int
tuple <string,int,string,string> decodeLine(string curLine)
{
  //receives one entire line, converts it into 4 strings (one for each word)
  string name = "";
  string number = "";
  int weight; // we'll need to convert string number to an int for the tuple
  string edge1 = "";
  string edge2 = "";
  int count = 0;
  bool loop = true;
  
  int length = curLine.length();//get length of each line
  
  //first loop to extract name
  while (loop == true && count < length)
  {
    // iterate until i hit first space - this means to get first word
    if (curLine[count] != ' ') 
    {
      //build the string letter by letter
      name+=curLine[count];
      count++;
    }
    else
    {
      loop = false;
    }
  }
  
  count++;//skip the space character
  loop = true;//reset loop to true
  //second loop to extract weight
  while (loop == true && count < length)
  {
    if (curLine[count] != ' ')
    {  
      number+=curLine[count];
      count++;
    }
    else
    {
      loop = false;
    }
  }
  stringstream ss;
  ss << number;
  ss >> weight;
  
  count++;
  loop = true;
  //third loop to extract edge1
  //if the count is greater than the line length, don't do anything
  while (loop == true && count < length)
  {
    if (curLine[count] != ' ')
    {
      edge1+=curLine[count];
      count++;
    }
    else
    {
      loop = false;
    }
  }
  
  //for loop to extract edge2 rather than while loop, so that i stay in bounds of the line character count
  count++;
  for (int i=count; i<length; i++)//loop with fixed length to avoid error
  {
    edge2+=curLine[i];
  }
  
  return createTuple(name, weight, edge1, edge2);
}

//map
vector<tuple<int, int, int, int>> createMap(vector<tuple<string,int,string,string>> stringVector)
{
  
  vector<tuple<int,int,int,int>> intVector;
  
  std::unordered_map<string,int> map;
  
  for (size_t i = 0; i < stringVector.size(); i++)
  {
    map[get<0>(stringVector[i])] = i;
  }
  
  map[""] = -1;
  
  for (size_t j = 0; j < stringVector.size(); j++)
  {
    //make tuple
    int one = map[get<0>(stringVector[j])];
    int two = get<1>(stringVector[j]);
    int three = map[get<2>(stringVector[j])];
    int four = map[get<3>(stringVector[j])];
    tuple <int, int, int, int> tup2;
    tup2 = make_tuple(one, two, three, four);
    intVector.push_back(tup2);
  }
  return intVector;
}

//receives a text file as an input and converts that text file into a vector of tuples
vector<tuple<string, int, string, string>> getVector(string textFile)
{
  //create vector of tuples
  vector<tuple<string, int, string, string>> vec;
  
  
  //first count the number of lines in the given text file to set the bounds
  fstream c;
  //c.open("sampletwo.txt", ios::in);
  c.open(textFile, ios::in);
  string curLine;
  int numberLines = 0;
  if (c.is_open())
  {
    string str;
    while (getline(c,str))
    {
      numberLines++;
    }
    c.close();
  }
  
  //decode the file by separating each line into the following format:
  //[string name] [int weight] [string edge 1] [string edge 2]
  fstream f;
  //f.open("sampletwo.txt", ios::in);
  f.open(textFile, ios::in);
  if (f.is_open())
  {
    for (int i = 0; i < numberLines; i++)
    {
        getline(f,curLine);
        tuple<string,int,string,string> myTuple = (decodeLine(curLine));
        //add to vector
        vec.push_back(myTuple);
    }
    f.close();
  }
  return vec;
}
