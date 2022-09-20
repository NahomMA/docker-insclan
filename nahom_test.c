#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#pragma GCC diagnostic ignored "-Wmultichar"

int checkNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return 1;
    }
    return 0;
}
// int string_nonzero_status=0;


int _test_is_dir(char *expression){
	/*	refer  to :
		https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/sys/stat.h
*/
    struct stat stats;
    stat(expression, &stats);
    // Check for file existence
    if (S_ISDIR(stats.st_mode)) {return 0;}
    else {return 1;}
}


int _test_file_exists(char *expression)
{   struct stat stats;
    stat(expression, &stats);   
    if (access(expression, F_OK) == 0 ) return 0;
	else return 1;

    }


int _test_is_file(char *expression){
	/*	refer  to :
		https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/sys/stat.h
*/
    struct stat st;
    stat(expression, &st);
    if (S_ISREG(st.st_mode)) return 0;
    else return 1; 

}


int _test_string_nonzero(char *expression)
{  
    return (strlen(expression)>0&&expression[0] != '\0' && expression[0] != ' ' )==1?0:1;  	
	
	
}



int _test_file_size_greater_than_zero(char *expression){ 	
	/*	refer  to :
		https://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/sys/stat.h
*/
    struct stat st;
    stat(expression, &st);    
    if (st.st_size>0 && access(expression, F_OK) == 0 && S_ISDIR(st.st_mode)==0 ) return 0; 
    else return 1;
}



/* implement = -eq -ne
  1.  STRING1 = STRING2: the strings are equal
  2. INTEGER1 -eq INTEGER2: INTEGER1 is equal to INTEGER2
  3. INTEGER1 -ne INTEGER2: INTEGER1 is not equal to INTEGER2
              
    */    

    int _2string2_equal(char *expression, char *expression2) {        
        return strcmp(expression, expression2)==0?0:1;
    }
     int _2ints_equal(int num1, int num2) {
     return num1==num2?0:1;
    }     
     
  



int main(int argc, char *argv[])
{
     int ch;   
     if(strcmp(argv[optind],"-eq")==0)
     { 
     if(argv[optind+2]==NULL||argv[optind+1]==NULL||checkNumber(argv[optind+2])==1||checkNumber( argv[optind+1])==1){
                printf("oops! \n");
                fprintf(stderr, "usage: utility_name [-eq] [num1] [num2] \n");
                return 1;
            }
            return _2ints_equal(atoi ( argv[optind+1] ),atoi( argv[optind+2] ) );
    
     }
     else if(strcmp(argv[1],"-ne")==0){
        if(argv[optind+2]==NULL||argv[optind+1]==NULL||checkNumber(argv[optind+2])==1||checkNumber( argv[optind+1])==1){
            printf("oops! \n");
            fprintf(stderr, "usage: utility_name [-eq] [num1] [num2] \n");
            return 1;
        }
        
        return !_2ints_equal(atoi ( argv[optind+1] ),atoi( argv[optind+2] ) );
     }


   else{
       while ((ch = getopt(argc, argv, "d:e:f:n:s:z:=:")) != -1) {
        switch (ch) {
        case 'd':           
	        return _test_is_dir(optarg);
            break;
        case 'e': 
	        return _test_file_exists(optarg);
            break;
        case 'f':
	        return _test_is_file(optarg);
            break;
        case 'n':                    
            return _test_string_nonzero(optarg);       
            break;	 
        case 's':
	        return _test_file_size_greater_than_zero(optarg);
            break;
        case 'z':
            return !_test_string_nonzero(optarg);
            break;
        case '=':            
            return  _2string2_equal(argv[optind-1],argv[optind]);
            break;        
        // case '-eq':
        //     printf("check argv %s opt @ optt ind %d=  .",argv[optind],optind);
        //     printf(" two size opt-ind==\n%c\n",ch);
        //     if(checkNumber(argv[optind])==1||checkNumber( argv[optind-1])==1){
        //         printf("You must submit a Number \n");
        //         return 1;
        //     }
        //     return _2ints_equal(atoi ( argv[optind-1] ),atoi( argv[optind] ) );
        //     break;
        // case '-ne':
        //     printf(" two size opt-ind==\n%c\n",ch);
        //     printf("check argv %s opt @ optt ind %d=  .",argv[optind],optind);
        //     return !_2ints_equal( atoi(argv[optind-1]),atoi(argv[optind]));
        //     break;
         
        default:
         fprintf(stderr, "usage: %s [-defnsz] [file or string]\n",argv[0]);    
        return 1;
        }
        
    
    }  


} // close else
  
    argc -= optind;
    argv += optind;

    return 1;
}
