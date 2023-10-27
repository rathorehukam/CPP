



#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int *quantities = new int[N];

    for(int i=0; i<N; i++){
        cin >> quantities[i];
    }

    int *modifiedQuantities = new int[N];
    for(int i=0; i<N; i++){
        int prev = (i==0) ? 0 : quantities[i-1];
        int next = (i==N-1) ? 0 : quantities[i+1];
        modifiedQuantities[i] = prev + next;
    }

    cout << "Modified array: ";
    for(int i=0; i<N; i++){
        cout << modifiedQuantities[i];
        if(i != N-1) cout << " ";  
    }
    cout << endl;

    delete[] quantities;
    delete[] modifiedQuantities;

    return 0;
}
