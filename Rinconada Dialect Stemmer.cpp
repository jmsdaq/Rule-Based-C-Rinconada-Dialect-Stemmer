/*

 **Rule-Based C++ Rinconada Dialect Stemmer**
 
 >>James Lorenz Cernechez * James Daquioag * Lance Kim Formales * Gerald Serrano
 >>BSCS 1C
 
*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int twoL(string D);
int threeL(string D);
int sixL(string D);

int main()
{
	int ans;
	string dialect;
	string pass, copy, copy1, copy2, copy3, copy4, copy5, copy6;
    
	start:
	system("CLS");
	cout<<"\n\tThis is a Bicol Rinconada Stemmer.";
	cout<<"\n\tGive me a Rinconada action word>> ";
	cin >> dialect;
	cout <<endl;
    
	// convert the dialect into lowercase.  	 
	for (int i = 0; i < dialect.length(); i++)
	{
    	dialect[i] = tolower(dialect[i]);
	}	 
	pass = dialect;
	copy = dialect; // use to manipulate to find the baseword.
	copy1 = dialect; // copy the original input
	copy2 = dialect; // use to manipulate to find the baseword.
	copy3 = dialect; // copy 3 and 6 use to know if the syllables after the prefix are repeated.
	copy4 = dialect; // use to get the prefix of baseword starts with vowels
	copy5 = dialect; // use to manipulate to know if the letters after the prefix is consonant or vowel.
	copy6 = dialect; // copy 3 and 6 use to know if the syllables after the prefix are repeated.
    
	//find prefixes
	int na = dialect.find("na");
	int ni = dialect.find("ni");
	int ma = dialect.find("ma");
	int mag = dialect.find("mag");
	int nag = dialect.find("nag");
	int mig = dialect.find("mig");
	int nipara = dialect.find("nipara");
    
	//find suffixes
	int an = dialect.find("an");
	int ngan = dialect.find("ngan");
	int han = dialect.find("han");
    
	while(true){
   	 
    	if((ma!=string::npos)&&(mag==string::npos)&&(na==string::npos))
    	{   
        	dialect.erase(dialect.begin()+2,dialect.end());
        	copy5.erase(0,2); // erase the first 3 letters.
        	copy5.erase(copy5.begin()+1,copy5.end()); // erase the 2nd to the last letters     	 
        	string c5 = copy5;    
       	 
        	if((ma!=string::npos)&&(an==string::npos)&&(ngan==string::npos)&&(na==string::npos))
        	{
            	if((c5=="a")||(c5=="e")||(c5=="i")||(c5=="o")||(c5=="u"))
            	{
                	cout<<"\tDid you mean: ";
                	copy1.insert(2, "-");
                	cout<<copy1<<endl<<endl;
                	cout << "\tTense: Future tense\n";
                                               	 
                	copy.erase(0,2); // erase the first 2 letters.
                	cout <<"\tBase word: " << copy <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + syllable"<<endl;
            	}
            	else if(c5 == "-")
            	{
                	cout << "\tTense: Future tense\n";
                                               	 
                	copy.erase(0,3); // erase the first 2 letters.
                	cout <<"\tBase word: " << copy <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + syllable"<<endl;
            	}
            	else if((c5!="a")||(c5!="e")||(c5!="i")||(c5!="o")||(c5!="u"))
            	{
                	cout << "\tTense: Future tense\n";
                                               	 
                	copy.erase(0,2); // erase the first 2 letters.
                	cout <<"\tBase word: " << copy <<endl;
                	cout <<"\tPrefix: " << dialect <<endl;
            	}
        	}
        	else if ((c5=="a")||(c5=="e")||(c5=="i")||(c5=="o")||(c5=="u"))
        	{    
            	copy6.erase(0,2); // erase the firs 3 letters.
            	copy6.erase(copy6.begin()+1,copy6.end()); // erase the 2nd to the last letters.     	 
           	 
            	copy3.erase(0,3); // erase the first 4 letters.
            	copy3.erase(copy3.begin()+1,copy3.end()); // erase the 2nd to the last letters.   	 
 
            	if(copy3==copy6)
            	{
                	cout<<"\tDid you mean: ";
                	copy1.insert(2, "-");
                	cout<<copy1<<endl<<endl;
                	cout << "\tTense: Future tense";
                                           	 
                	copy.erase(0,3); // erase the first 2 letters
                	copy.resize(copy.size() - 2); //erase the suffixes
                	cout <<"\n\tBase word: " << copy <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + First syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout<<"\tDid you mean: ";
                	copy1.insert(2, "-");
                	cout<<copy1<<endl<<endl;
                	cout << "\tTense: Future tense\n";
                                           	 
                	copy.erase(0,3); // erase the first 2 letters
                	copy.resize(copy.size() - 2); //erase the suffixes
                	cout <<"\tBase word: " << copy <<endl;
                	cout <<"\tPrefix: " << dialect <<"-"<<endl;
            	}   
        	}
    
        	else if (((c5 == "-")&&((an!=string::npos))||(han!=string::npos)))
        	{
                	copy6.erase(0,3); // erase the firs 2 letters.
                	copy6.erase(copy6.begin()+1,copy6.end()); // erase the 2nd to the last letters.     	 
           	 
                	copy3.erase(0,4); // erase the first 4 letters.
                	copy3.erase(copy3.begin()+1,copy3.end()); // erase the 2nd to the last letters.   	 
    
                	if(copy3==copy6)
                	{
                    	cout << "\tTense: Future tense\n";
                                               	 
                    	copy.erase(0,4); // erase the first 2 letters.
                    	copy.resize(copy.size() - 2); //erase the suffixes
                    	cout <<"\tBase word: " << copy <<endl;
                    	cout <<"\tPrefix: " << dialect <<"- + syllable"<<endl;
                	}
       	 
                	else
                	{
                    	cout << "\tTense: Future tense\n";
                                           	 
                    	copy.erase(0,3); // erase the first 2 letters.
                    	copy.resize(copy.size() - 2); //erase the suffixes
                    	cout <<"\tBase word: " << copy <<endl;
                    	cout <<"\tPrefix: " << dialect <<"-" <<endl;
                	}
        	}
        	else if((c5 == "-")&&(han!=string::npos))
            	{
                	copy6.erase(0,3); // erase the firs 2 letters.
                	copy6.erase(copy6.begin()+1,copy6.end()); // erase the 2nd to the last letters.     	 
           	 
                	copy3.erase(0,4); // erase the first 4 letters.
                	copy3.erase(copy3.begin()+1,copy3.end()); // erase the 2nd to the last letters.   
               	 
                	if(copy3==copy6)
                	{
                    	cout << "\tTense: Future tense\n";
                                               	 
                    	copy.erase(0,4); // erase the first 2 letters.
                    	copy.resize(copy.size() - 3); //erase the suffixes
                    	cout <<"\tBase word: " << copy <<endl;
                    	cout <<"\tPrefix: " << dialect <<"- + syllable"<<endl;
                	}
               	 
            	}    
        	else if ((((c5!="a")||(c5!="e")||(c5!="i")||(c5!="o")||(c5!="u"))&&(ngan!=string::npos))||(an!=string::npos))
        	{      	 
            	copy6.erase(0,2);
            	copy6.erase(copy6.begin()+2,copy6.end());      	 
           	 
            	copy3.erase(0,4);
            	copy3.erase(copy3.begin()+2,copy3.end());      	 
 
            	if(copy3==copy6)
            	{
                	cout << "\tTense: Future tense\n";
                                           	 
                	copy.erase(0,4); // erase the first 2 letters.
                	copy.resize(copy.size() - 2); //erase the suffixes
                	cout <<"\tBase word: " << copy <<endl;
                	cout <<"\tPrefix: " << dialect <<" + First syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout << "\tTense: Future tense\n";
                                         	 
                	copy.erase(0,2); // erase the first 2 letters.
                	copy.resize(copy.size() - 2); //erase the suffixes
                	cout <<"\tBase word: " << copy <<endl;
                	cout <<"\tPrefix: " << dialect <<endl;
            	}
        	}
        	cout<<"\n\t"<<dialect << " is usually used in all municipality and city of Rinconada";
    	}
    
    	else if((na!=string::npos)&&(nag==string::npos)&&(ma==string::npos))//||((dialect == "ni")&&(pis==string::npos)))
    	{   
        	dialect.erase(dialect.begin()+2,dialect.end());
        	copy5.erase(0,2); // erase the first 3 letters.
        	copy5.erase(copy5.begin()+1,copy5.end()); // erase the 2nd to the last letters     	 
        	string c5 = copy5;    
       	 
        	if ((c5=="a")||(c5=="e")||(c5=="i")||(c5=="o")||(c5=="u"))
        	{    
            	copy6.erase(0,2); // erase the firs 3 letters.
            	copy6.erase(copy6.begin()+1,copy6.end()); // erase the 2nd to the last letters.     	 
           	 
            	copy3.erase(0,3); // erase the first 4 letters.
            	copy3.erase(copy3.begin()+1,copy3.end()); // erase the 2nd to the last letters.   	 
 
            	if(copy3==copy6)
            	{
                	cout<<"\tDid you mean: ";
                	copy1.insert(2, "-");
                	cout<<copy1<<endl<<endl;
                	cout << "\tTense: Present tense\n";
                                           	 
                	copy2.erase(0,3);
                	cout <<"\n\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + First syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout<<"\tDid you mean: ";
                	copy1.insert(2, "-");
                	cout<<copy1<<endl<<endl;
                	cout << "\tTense: Past tense\n";
                                           	 
                	copy2.erase(0,2);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"-"<<endl;
            	}   
        	}
       	 
        	else if(c5 == "-")
        	{    
            	copy6.erase(0,3); // erase the firs 2 letters.
            	copy6.erase(copy6.begin()+1,copy6.end()); // erase the 2nd to the last letters.     	 
           	 
            	copy3.erase(0,4); // erase the first 4 letters.
            	copy3.erase(copy3.begin()+1,copy3.end()); // erase the 2nd to the last letters.   	 
 
            	if(copy3==copy6)
            	{
                	cout << "\tTense: Present tense\n";
                                           	 
                	copy2.erase(0,4);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout << "\tTense: Past tense\n";
                                           	 
                	copy2.erase(0,3);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"-" <<endl;
            	}   
        	}
              	 
        	else if((c5!="a")||(c5!="e")||(c5!="i")||(c5!="o")||(c5!="u"))
        	{      	 
            	copy6.erase(0,1);
            	copy6.erase(copy6.begin()+2,copy6.end());      	 
           	 
            	copy3.erase(0,3);
            	copy3.erase(copy3.begin()+2,copy3.end());      	 
 
            	if(copy3==copy6)
            	{
                	cout << "\tTense: Present tense\n";
                                           	 
                	copy2.erase(0,4);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + First syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout << "\tTense: Past tense\n";
                                         	 
                	copy2.erase(0,2);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<endl;

            	}
        	}
        	cout<<"\n\t"<<dialect << " is usually used in all municipality and city of Rinconada";
    	}
   	 
    	else if ((mig!=string::npos)||(mag!=string::npos))//((dialect == "mig")||(dialect == "mag"))
    	{   
        	dialect.erase(dialect.begin()+3,dialect.end());
        	copy5.erase(0,3); // erase the first 3 letters.
        	copy5.erase(copy5.begin()+1,copy5.end()); // erase the 2nd to the last letters     	 
        	string c5 = copy5;
   	 
        	if ((c5=="a")||(c5=="e")||(c5=="i")||(c5=="o")||(c5=="u"))
        	{
            	cout<<"\tV3Did you mean: ";
            	copy1.insert(3, "-");
            	cout<<copy1<<endl<<endl;
            	cout << "\tTense: Future tense\n";
                   	 
            	copy1.erase(0,4); // erase the first 3 letters.	 
            	cout <<"\tBase word: " << copy1<<endl;
            	cout <<"\tPrefix: " << dialect <<endl;
           	 
        	}
        	else if(c5 == "-")
        	{
            	cout << "\tTense: Future tense\n";
               	 
            	copy.erase(0,4); // erase the first 3 letters.	 
            	cout <<"\tBase word: " << copy;
           	 
            	cout <<"\t\nPrefix: " << dialect <<endl;
        	}
   	 
        	else if((c5!="a")||(c5!="e")||(c5!="i")||(c5!="o")||(c5!="u"))
        	{
            	cout << "\tTense: Future tense\n";
                   	 
            	copy.erase(0,3); // erase the first 3 letters.	 
            	cout <<"\tBase word: " << copy;
            	cout <<"\n\tPrefix: " << dialect <<endl;
        	}
        	cout<<"\n\t"<<dialect << " is usually used in all municipality and city of Rinconada except Balatan";    
    	}
   	 
    	else if(nag!=string::npos)
    	{   
        	dialect.erase(dialect.begin()+3,dialect.end());
        	copy5.erase(0,3); // erase the first 3 letters.
        	copy5.erase(copy5.begin()+1,copy5.end()); // erase the 2nd to the last letters     	 
        	string c5 = copy5;    
       	 
        	if ((c5=="a")||(c5=="e")||(c5=="i")||(c5=="o")||(c5=="u"))
        	{    
            	copy6.erase(0,3); // erase the firs 3 letters.
            	copy6.erase(copy6.begin()+1,copy6.end()); // erase the 2nd to the last letters.     	 
           	 
            	copy3.erase(0,4); // erase the first 4 letters.
            	copy3.erase(copy3.begin()+1,copy3.end()); // erase the 2nd to the last letters.   	 
 
            	if(copy3==copy6)
            	{
                	cout<<"\tDid you mean: ";
                	copy1.insert(3, "-");
                	cout<<copy1<<endl<<endl;
                	cout << "\tTense: Present tense\n";
                                           	 
                	copy2.erase(0,4);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + First syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout<<"\tDid you mean: ";
                	copy1.insert(3, "-");
                	cout<<copy1<<endl<<endl;
                	cout << "\tTense: Past tense\n";
               	 
                                           	 
                	copy2.erase(0,3);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"-"<<endl;
            	}
        	}
       	 
        	else if(c5 == "-")
        	{    
            	copy6.erase(0,4); // erase the firs 3 letters.
            	copy6.erase(copy6.begin()+1,copy6.end()); // erase the 2nd to the last letters.     	 
           	 
            	copy3.erase(0,5); // erase the first 4 letters.
            	copy3.erase(copy3.begin()+1,copy3.end()); // erase the 2nd to the last letters.   	 
 
            	if(copy3==copy6)
            	{
                	cout << "\tTense: Present tense\n";
                	copy1.erase(copy1.begin()+4, copy1.end());
               	 
                                           	 
                	copy2.erase(0,5);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<"- + First syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout << "\tTense: Past tense\n";
                                           	 
                	copy2.erase(0,4);
                	cout <<"\tBase word: " << copy2 <<endl;  	 
                	cout <<"\tPrefix: " << dialect <<"-"<<endl;
            	}   
        	}
              	 
        	else if((c5!="a")||(c5!="e")||(c5!="i")||(c5!="o")||(c5!="u"))
        	{      	 
            	copy6.erase(0,3);
            	copy6.erase(copy6.begin()+2,copy6.end());      	 
           	 
            	copy3.erase(0,5);
            	copy3.erase(copy3.begin()+2,copy3.end());      	 
 
            	if(copy3==copy6)
            	{
                	cout << "\tTense: Present tense\n";
               	 
                                           	 
                	copy2.erase(0,5);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<" + First syllable"<<endl;
            	}
       	 
            	else
            	{
                	cout << "\tTense: Past tense\n";
               	 
                                         	 
                	copy2.erase(0,3);
                	cout <<"\tBase word: " << copy2 <<endl;
                	cout <<"\tPrefix: " << dialect <<endl;
            	}
        	}
        	cout<<"\n\t"<<dialect << " is usually used in all municipality and city of Rinconada";
    	}
    	else if (nipara!=string::npos)
    	{
        	dialect.erase(dialect.begin()+6,dialect.end());
       	 
   	 	copy5.erase(0,6); // erase the first 3 letters.
        	copy5.erase(copy5.begin()+1,copy5.end()); // erase the 2nd to the last letters     	 
        	string c5 = copy5;    
       	 
        	if ((c5=="a")||(c5=="e")||(c5=="i")||(c5=="o")||(c5=="u"))
        	{    
            	cout<<"\tDid you mean: ";
            	copy1.insert(6, "-");
            	cout<<copy1<<endl<<endl;
            	cout << "\tTense: Present tense\n";
            	cout <<"\tPrefix: " << dialect <<"-"<<endl;
                                           	 
            	copy2.erase(0,6);
            	cout <<"\tBase word: " << copy2 <<"\n";
        	}
   	 
        	else if(c5 == "-")
        	{    
            	cout << "\tTense: Present tense\n";
           	 
            	copy2.erase(0,7);
            	cout <<"\tBase word: " << copy2 <<"\n";
            	cout <<"\tPrefix: " << dialect <<"-"<<endl;
        	}
        	else if((c5!="a")||(c5!="e")||(c5!="i")||(c5!="o")||(c5!="u"))
        	{      	 
            	copy6.erase(0,5);
            	copy6.erase(copy6.begin()+2,copy6.end());
           	 
            	copy3.erase(0,7);
            	copy3.erase(copy3.begin()+2,copy3.end());      	 
 
            	if(copy3!=copy6)
            	{
                	cout << "\tTense: Present tense\n";
                                           	 
                	copy2.erase(0,6);
                	cout <<"\tBaseword: " << copy2 <<"\n";
                	cout <<"\tPrefix: " << dialect <<endl;
            	}
        	}
        	cout<<"\n\t"<<dialect << " is usually used in Buhi";
    	}
    	else
    	{
        	cout << "\tInvalid input.\n";
    	}
    	break;
	}
	cout<<"\n\n\tTry again?\n  \t0 - No\n  \t1 - Yes\n\t:: ";
    cin>>ans;
    if(ans==1)
    goto start; //jumps execution to the BACK label
    else
    cout<<"\n\tThank you!!!";
	return 0;
}
