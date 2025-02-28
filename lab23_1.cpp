#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

char score2grade(int score){
    if(score >= 80) return 'A';
    if(score >= 70) return 'B';
    if(score >= 60) return 'C';
    if(score >= 50) return 'D';
    else return 'F';
}

string toUpperStr(string x){
    string y = x;
    for(unsigned i = 0; i < x.size();i++) y[i] = toupper(x[i]);
    return y;
}

void importDataFromFile(string &Filetext, vector<string> &names, vector<int> &scores, vector<char> &grades){
    ifstream file(Filetext);
    string line;
    
    while (getline(file,line))
    {
       char name[50]; int sc1,sc2,sc3;
       int sum=0;
       sscanf(line.c_str(),"%[^:]: %d %d %d",name,&sc1,&sc2,&sc3);
       sum = sc1+sc2+sc3;
       names.push_back(name);
       scores.push_back(sum);

       grades.push_back(score2grade(sum));
    }
    
    file.close();
}

void getCommand(string &command,string &key){
    string comAndkey;
    
    cout << "Please input your command:" << endl;
    getline (cin,comAndkey);

    char com[50] , ky[50];
    com[0] = '\0';
    ky[0] = '\0';
    if(sscanf(comAndkey.c_str(),"%s %[^\n]",com,ky) > 0){
        command = com;
        key = ky;
    }
}

void searchName(vector<string> &names, vector<int> &scores, vector<char> &grades, const string &key){
    bool found = false;
    string Upkey = toUpperStr(key);
    
    for (unsigned int i = 0; i < names.size(); i++)
    {
        if (toUpperStr(names[i]) == Upkey)
        {
            cout << "---------------------------------" << endl;
            cout << names[i] << "'s score = " << scores[i] << endl;
            cout << names[i] << "'s grade = " << grades[i] << endl;
            cout << "---------------------------------" << endl;
            found = true;
        }
        
    }

    if (!found)
    {
        cout << "---------------------------------" << endl;
        cout << "Cannot found." << endl;
        cout << "---------------------------------" << endl;
    }
    

    
}

void searchGrade(vector<string> &names, vector<int> &scores, vector<char> &grades, string key){
    bool found = false;
    string Upkey = toUpperStr(key);

    cout << "---------------------------------" << endl;
    
     for (unsigned int i = 0; i < grades.size(); i++) {
        if (grades[i] == Upkey[0]) {  
            cout << names[i] << " (" << scores[i] << ")" << endl;
            found = true;
        }
    }

    if (!found)
    {
       
        cout << "Cannot found." << endl;
    
    }

    cout << "---------------------------------" << endl;
}


int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);
    
    do{
        string command, key;
        getCommand(command,key);
        command = toUpperStr(command);
        key = toUpperStr(key);
        if(command == "EXIT") break;
        else if(command == "GRADE") searchGrade(names, scores, grades, key);
        else if(command == "NAME") searchName(names, scores, grades, key);
        else{
            cout << "---------------------------------\n";
            cout << "Invalid command.\n";
            cout << "---------------------------------\n";
        }
    }while(true);
    
    return 0;
}

/*int main(){
    string filename = "name_score.txt";
    vector<string> names;
    vector<int> scores;
    vector<char> grades; 
    importDataFromFile(filename, names, scores, grades);

    string command, key;
    getCommand(command,key);
    
}*/
