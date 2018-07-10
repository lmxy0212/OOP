#include "std_lib_facilities.h"
int main(){
    cout << "Enter recent temperatures and we will calculates their average:\n";
    vector<string> text;
    
    for(string s; cin >> s;) text.push_back(s);

    for(string word : text) cout << "unsorted: " << word << "\n";
    
    sort(text);
	
	for(string word : text) cout << "sorted: " << word << "\n";


	int count = 1;
	string prev = text[0];
	for(int i = 1; i < text.size(); i ++){
		string next = text[i];
		if(prev == next){
			count ++;
		}
		else{
			cout << "word: " << prev << " count: " << count << "\n";
			prev = next;
			count = 1;
		}

	}
	cout << "word: " << prev << " count: " << count << "\n";

    return 0;
}
