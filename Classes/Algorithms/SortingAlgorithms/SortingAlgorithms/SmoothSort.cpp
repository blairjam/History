#include "SmoothSort.hpp"
#include "Statistics.hpp"
#include <iostream>
#include <bitset>

const size_t NumLeonardoNumbers = 46;

const size_t LeonardoNumbers[NumLeonardoNumbers] = {
    1u, 1u, 3u, 5u, 9u, 15u, 25u, 41u, 67u, 109u, 177u, 287u, 465u, 753u,
    1219u, 1973u, 3193u, 5167u, 8361u, 13529u, 21891u, 35421u, 57313u, 92735u,
    150049u, 242785u, 392835u, 635621u, 1028457u, 1664079u, 2692537u,
    4356617u, 7049155u, 11405773u, 18454929u, 29860703u, 48315633u, 78176337u,
    126491971u, 204668309u, 331160281u, 535828591u, 866988873u, 1402817465u,
    2269806339u, 3672623805u
};

struct HeapShape
{
    std::bitset<NumLeonardoNumbers> trees;

    size_t smallestTreeSize;
};

SmoothSort::SmoothSort(std::vector<int> dataStorage)
        : dataStorage(dataStorage), timer("SmoothSortTimer")
{
}

void SmoothSort::sort()
{
    timer.start();


    timer.stop();
}

std::string SmoothSort::getElapsedTime()
{
    return Statistics::convertTime(timer.getElapsedTime());
}
/*
std::vector<int>::iterator secondChild(std::vector<int>::iterator root)
{
    return root - 1;
}

std::vector<int>::iterator secondChild(std::vector<int>::iterator root)
{
    return secondChild(root) - LeonardoNumbers[size - 2];
}*/
