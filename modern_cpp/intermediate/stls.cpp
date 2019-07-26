 #include <algorithm>
 #include <iostream>
 #include <memory>
 #include <vector>
 #include <map>


 using namespace std;

 int main(int argc, char const *argv[])
 {
     vector<int> v{2,21,1,2,2,3,5,8,13};
     vector<int> p{1,3,5,8,21};
     map<int,int> monLength{
         {1,31},{2,28},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31}
         ,{9,30},{10,31},{11,30},{12,31}
     };
     int const traget = 2;
     int cnt = 0;

     for (int i = 0; i < v.size(); i++)
     {
         if(v[i] == traget){
            cnt++;
         }
     }

     cout << cnt << endl;

     auto twos = find(v.begin(),v.end(),2);
     auto prime = find_first_of(v.begin(),v.end(),p.begin(),p.end());
     int odds = count_if(v.begin(),v.end(),[](auto elem){return elem%2 != 0;});
     int getMon = count_if(monLength.begin(),monLength.end(),[](auto len){return len.second == 31;});
     
     prime += 1;
    //  cout << *twos << endl;
     cout << *prime << endl;
     prime += 1;
     cout << *prime << endl;
    //  cout << getMon << endl;
     
     return 0;
 }
 