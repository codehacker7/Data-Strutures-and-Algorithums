#include<iostream>
#include<vector>
#include<climits>
#include<cstdlib>
#include <algorithm>

using namespace std;

bool isSolution(int distance, vector<int>& stalls, int cows) {
    int totalCows = 1;
    int lastCowPos = stalls[0];
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - lastCowPos >= distance) {
            totalCows++;
            lastCowPos = stalls[i];
        }
    }
    
    return totalCows >= cows;
}


int main() {

	int totalnumberStalls;
	cin>>totalnumberStalls;

	int numberofcows;
	cin>>numberofcows;


	vector<int> stalls(totalnumberStalls);

	for(int i=0;i<totalnumberStalls;i++){
		cin>>stalls[i];
	}
	sort(stalls.begin(), stalls.end());

	
	int maxi = INT_MIN;
	int mini = INT_MAX;
	
	for(int i=0;i<totalnumberStalls;i++){
		maxi = max(maxi,stalls[i]);
		mini = min(mini,stalls[i]);
	}
	
	int low =1;
	int high = (maxi - mini);

	int ans = -1;

	while(low<=high){

		int mid = (low+high)/2;

		if(isSolution(mid,stalls,numberofcows)){
			low = mid+1;
		}
		else{
			high = mid-1;
		}

	}


	// the below code was made with idea of linear search
	// for(int i=low;i<=high;i++){

	// 	if(isSolution(i,stalls,numberofcows))
	// 	{
	// 		ans = max(ans,i);
			
	// 	}
	// 	else{
	// 		break;
	// 	}
	
	
	// }
	cout << high <<endl;

	return 0;
}