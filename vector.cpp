#include <iostream>
#include <vector>
#include <fstream>
#include<string>
#include<algorithm>
using namespace std;

void split(std::string& s, std::string& delim,std::vector< std::string >* ret)  
{  
    size_t last = 0;  
    size_t index=s.find_first_of(delim,last);  
    while (index!=std::string::npos)  
    {  
        ret->push_back(s.substr(last,index-last));  
        last=index+1;  
        index=s.find_first_of(delim,last);  
    }  
    if (index-last>0)  
    {  
        ret->push_back(s.substr(last,index-last));  
    }  
}  
/*single*/
void check_statistic(std::vector< std::string >* ret,std::string item){
	vector<string>::iterator iter = std::find(ret->begin(), ret->end(), item);
	if(iter!=ret->end()){
    //找到
}else{
	ret->push_back(item);
    //没找到
}
}

int index(std::vector<std::string>* ret, std::string item){
	int index=0;
	for(string i:*ret){
		if(i==item) break;
		index++;
	}
	return index;
}

int main(){
	string file("kddcup.data_10_percent.csv.arff");
	ifstream infile;
	infile.open(file.data());
	ofstream outfile("out.csv", ofstream::app);
        ofstream convert_format("convert.csv", ofstream::app);
	string s;
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
	vector<string> line_string;
	string delim(",");
	int count=0;
	string new_string;
	while(getline(infile,s)){
		split(s,delim,&line_string);
		check_statistic(&v1,line_string[1]);	
                check_statistic(&v2,line_string[2]);
                check_statistic(&v3,line_string[3]);
		line_string[1]=to_string(index(&v1,line_string[1]));
                line_string[2]=to_string(index(&v2,line_string[2]));
                line_string[3]=to_string(index(&v3,line_string[3]));
		new_string="";
		for(string item:line_string){
			new_string+=item;
			new_string+=",";
		}
		new_string=new_string.substr(0,new_string.size()-1);
		outfile<<new_string<<endl;;
		line_string.clear();
	}
	for(string i:v1)
		convert_format<<i<<":"<<count++<<endl;
	count=0;
        for(string i:v2)
                convert_format<<i<<":"<<count++<<endl;
	count=0;
        for(string i:v3)
                convert_format<<i<<":"<<count++<<endl;

/*
	while(getline(infile,s)){
		split(s,delim,&line_string);
		cout<<line_string[1]<<":"<<index(&v1,line_string[1]);
                cout<<line_string[2]<<":"<<index(&v2,line_string[2]);
                cout<<line_string[3]<<":"<<index(&v3,line_string[3]);

		line_string.clear();
	}
	for(int i=0;i!=100;i++){
		v2.push_back(i);
	}

		cout<<i<<endl;
*/	return 0;	
}
