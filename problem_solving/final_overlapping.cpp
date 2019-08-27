#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>



/*We want to read from text file that contains line of numbers where
each number represent index of image and we divide each cluster each otehr*/
using Cluster = std::vector<int>;
using ClusterVector = std::vector<Cluster>;
using multipleVectors = std::vector<std::vector<std::pair<int, int>>>;
using vectPairs = std::vector<std::pair<int, int>>;
using pairsIterator = std::vector<std::pair<int, int>>::iterator;

void splitString(std::string& SingleCluster, ClusterVector& clusterVector) {

	Cluster cluster;
	// index of image;
	std::string number;
	// Convert string line to stream
	std::stringstream ImageIndex(SingleCluster);

	while (std::getline(ImageIndex, number, ',')) {
		//Push every index into the inner vector
		cluster.push_back(std::stoi(number));
	}
	clusterVector.push_back(cluster);
}


std::vector<std::pair<int, int>> SubVector(std::vector<int>& vec2, std::vector<int>& vec1){

	//Result of subtraction
	std::vector<std::pair<int, int>> Result;

	//pick element of sec vector and subtract it from each element in the first vector
	for (int i = 0; i < vec2.size(); i++)
	{
		int CurrentValueOfSubtraction = vec2[i];

		for (auto& element : vec1) {
			int ResultOfSub = CurrentValueOfSubtraction - element;
			Result.emplace_back(CurrentValueOfSubtraction, ResultOfSub);
		}
	}

	return Result;
}

vectPairs getMultiVector(multipleVectors mul)
{
    //  vect vec;
    vectPairs tmpvec = mul[0];
    int min = std::abs(mul[0][0].second);
    for (int i = 0; i < mul.size(); i++)
    {
        if (std::abs(mul[i][0].second) < min)
        {
            min = std::abs(mul[i][0].second);
            tmpvec = mul[i];
        }
    }

    return tmpvec;
}

//This function returns vector of int (Final overlapping)
Cluster overLap(vectPairs vectorOfPairs)
{
    //std::vector<int> vecSubstraction;
    pairsIterator itr;
    std::sort(std::begin(vectorOfPairs), std::end(vectorOfPairs), [](std::pair<int, int> const &lhs, std::pair<int, int> const &rhs) {
        return std::abs(lhs.second) < std::abs(rhs.second);
    });

    std::set<int> cluster;

    for (itr = vectorOfPairs.begin(); itr != vectorOfPairs.end(); ++itr)
    {
        int item1 = itr->first;
        int item2 = itr->first - itr->second;
        if (cluster.size() < 6)
            cluster.insert(item1);
        if (cluster.size() < 6)
            cluster.insert(item2);
    }

    return Cluster(cluster.begin(), cluster.end());
}

int main() {

	//read from Text file
	std::string FilePath = R"(/home/omar/Documents/cpp_problems/overlapping/clusters_for_steel_structure_.txt)";
	std::ifstream IndiciesFile(FilePath);

	//Creating vector of vector indices where each internal vector is a cluster
	std::vector<std::vector<int>> VectorOfOuterIndices;


	if (IndiciesFile.is_open()) {
		// For each line in file
		for (std::string SingleCluster; std::getline(IndiciesFile, SingleCluster); ) {
			// print current line
			//std::cout << SingleCluster << "\n";

			splitString(SingleCluster, VectorOfOuterIndices);

		}
	}


    std::vector<std::vector<std::vector<std::pair<int, int>>>> PairOfsubtraction;
	int counter = 0;
    for (int i = 2; i < VectorOfOuterIndices.size()+1; i++){
        std::vector<std::vector<std::pair<int, int>>> InnerVec;
        if (counter >= 1){
            //Subtract vector from its two previous
            auto resultPairOfSub2 = SubVector(VectorOfOuterIndices[i - 1], VectorOfOuterIndices[i - 2]);
            auto resultPairOfSub3 = SubVector(VectorOfOuterIndices[i - 1], VectorOfOuterIndices[i - 3]);
            //fill the result into the PairOfsubtraction
            InnerVec.push_back(resultPairOfSub2);
            InnerVec.push_back(resultPairOfSub3);
        }
        else {
            //subtract vector from the one
            auto resultPairOfSub1 = SubVector(VectorOfOuterIndices[i - 1], VectorOfOuterIndices[i - 2]);
            InnerVec.push_back(resultPairOfSub1);
                counter++;
        }
        PairOfsubtraction.push_back(InnerVec);
    }

    std::vector<int> overLapping;

    for(int i = 0; i<PairOfsubtraction.size(); i++){

    auto minSubVect = getMultiVector(PairOfsubtraction[i]);
    overLapping = overLap(minSubVect);
    
    for(auto item : overLapping){
        std::cout << item  << " ";
       
    }
    std::cout << std::endl;
    }
    

    


	return 0;
}



	