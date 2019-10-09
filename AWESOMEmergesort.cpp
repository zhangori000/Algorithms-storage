// this is the traditional way of doing it. Making new arrays at each call stack

//this results in a big O(nlgn) space (roughly) 

#include <vector>
using namespace std;

vector<int>merge(vector<int> left, vector<int> right);
vector<int> mergeSort(vector<int> array) {
	// Write your code here.
	//so tosimply write a merge, u need a mid point.
	if(array.size() == 1)
	{
		return array;
	}
	int mid = (array.size()-1) / 2;
	vector<int> leftHalf;
	vector<int> rightHalf;
	for(int i = 0; i < mid+1; i++)
	{
		leftHalf.push_back(array[i]);
	}
	for(int i = mid+1; i < array.size(); i++)
	{
		rightHalf.push_back(array[i]);
	}
	return merge(mergeSort(leftHalf), mergeSort(rightHalf));
	
}

vector<int> merge(vector<int>leftHalf, vector<int> rightHalf)
{
	int i = 0;
	int j = 0;
	int k = 0;
	vector<int> arr(leftHalf.size() + rightHalf.size());
	while(i < leftHalf.size() && j < rightHalf.size())
	{
		if(leftHalf[i] <= rightHalf[j])
		{
			arr[k] = leftHalf[i];
			i++;
			k++;
		}
		else
		{
			arr[k] = rightHalf[j];
			j++;
			k++;
		}
	}
	while(i < leftHalf.size())
	{
		arr[k] = leftHalf[i];
		i++;
		k++;
	}
	while(j < rightHalf.size())
	{
		arr[k] = rightHalf[j];
		j++;
		k++;
	}
	return arr;
}


// the better optimized solution.

	
