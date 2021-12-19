#ifndef VECTORTUPLE_H
#define VECTORTUPLE_H

#pragma once
#include <vector>
#include <tuple>

std::tuple <std::string,int,std::string,std::string> decodeLine(std::string curLine);

std::tuple <std::string,int,std::string,std::string> createTuple(std::string name, int weight, std::string edge1, std::string edge2);

std::vector<std::tuple<std::string, int, std::string, std::string>> getVector(std::string textFile);

std::vector<std::tuple<int, int, int, int>> createMap(std::vector<std::tuple<std::string, int, std::string, std::string>>);


#endif