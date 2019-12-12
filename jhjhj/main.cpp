//
//  main.cpp
//  jhjhj
//
//  Created by 王志鹏 on 2019/12/12.
//  Copyright © 2019 wangzhipeng. All rights reserved.
//
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>


using namespace std;
#define MAX_LENGTH 1<<10


typedef struct{
   string str;
   int cnt;
}word;


int number_of_words=0;
vector<string> virtual_word;
vector<string> raw_word;
vector<word> word_statistics;



bool cmp_raw_word(const string &a,const string &b){return a<b;}



bool cmp_word_statistics(const word &a,const word &b){return a.cnt>b.cnt;}



bool skip(){ scanf("%*[^a-z||A-Z]"); return true;}


int main()
{

   clock_t start,finish;
   double totaltime;
   start=clock();


   printf("Wait for a moment please.\n");


   
   word w;
   char _word[MAX_LENGTH];


   vector<string>::iterator it,last;
   vector<word>::iterator wit;


 
   freopen("/Users/wangzhipeng/input.txt","r",stdin);
   while(skip()&&scanf("%[a-zA-Z]",_word)!=EOF)
   {
      number_of_words++;
     
      if(_word[1]!='\0'&&isupper(_word[0])&&islower(_word[1])) _word[0]|=1<<5;
      raw_word.push_back(_word);
   }


   freopen("/Users/wangzhipeng/out.txt","w",stdout);
   printf("-----------------------------------------------\n");
   printf("%d words be counted! \nDetails are as follow:\n",number_of_words);
   printf("no.   word              time          frequency\n");
   printf("-----------------------------------------------\n");



   if(!raw_word.size())
   {
      printf("There is no word in the \"in.txt\" or \"in.txt\" inexistence!\n");
      printf("-----------------------------------------------\n");
      return 0;
   }



   sort(raw_word.begin(),raw_word.end(),cmp_raw_word);
   for(last=raw_word.begin(),it=raw_word.begin()+1;it!=raw_word.end();it++)
   {
      if(*it!=*last)
      {
         w.str=*last;
         w.cnt=it-last;

         if(!binary_search(virtual_word.begin(),virtual_word.end(),*last)) word_statistics.push_back(w);
         last=it;
      }
   }



   w.str=*last;
   w.cnt=it-last;
   if(!binary_search(virtual_word.begin(),virtual_word.end(),*last)) word_statistics.push_back(w);


   sort(word_statistics.begin(),word_statistics.end(),cmp_word_statistics);
   bool b=false;
   for(wit=word_statistics.begin();wit!=word_statistics.end();wit++)
   {

      if((*wit).cnt*1.0/number_of_words>=0.05||((*wit).cnt>=2&&(*wit).cnt*100.0/number_of_words>=0.01)){
          printf("[%04d] %-16s (%5d)\n",wit-word_statistics.begin()+1,((*wit).str).c_str(),(*wit).cnt);
          b=true;
      }
   }



   if(!b)printf("no appropriate word!\n");
   printf("-----------------------------------------------\n");



   finish=clock();
   totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
   printf("The program cost %.4lf second(s)",totaltime);
    printf("thank you~~~~\n");
    printf("name: wangzhipeng\n");
    printf("id:20191806\n");
   return 0;
}

