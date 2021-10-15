#ifndef datum
#define datum

//Define structure and type
    struct _Date_ {

    int day;
    int month;
    int year;

    };

    typedef struct _Date_ Date;


//Define allocation functions

    // allocate and initialize new date
    Date* newDate(int d, int m, int y){

        Date* date=malloc(sizeof(Date));
        assert(date!=NULL);
        
        date->day=d;
        date->month=m;
        date->year=y;

    return date;
    }

    //Deallocate memory
    Date* delDate(Date* date){
        
        assert(date!=NULL);
//        if (date -> day != NULL){
//            free(date->day);
//        }
//        if (date -> month!= NULL){
//            free(date->month);
//        }
//        if (date -> year!= NULL){
//            free(date->year);
//        }

        free(date);
        return NULL;

    }




//Define mutator functions
    
    void setDateDay(Date* date, int d){
        assert(date!=NULL);
        date->day=d;
    }

    void setDateMonth(Date* date, int m){
        assert(date!=NULL);
        date->month=m;
    }

    void setDateYear(Date* date, int y){
        assert(date!=NULL);
        date->year=y;
    }

    int getDateDay(Date* date){
        assert(date!=NULL);
        return date->day;
    }

    int getDateMonth(Date* date){
        assert(date!=NULL);
        return date->month;
    }
    
    int getDateYear(Date* date){
        assert(date!=NULL);
        return date->year;
    }


//Define checking function

    int isMeaningful(Date* date){

            assert(date!=NULL);
        int r;
        int dd=date->day;
        int mm=date->month;
        int yy=date->year;

    //check year
       if(yy>=1900 && yy<=9999){
             //check month
            if(mm>=1 && mm<=12) {
                //check days

                //months with 31 days
                if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12))
                    r=1;

                    //months with 30 days
                else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11))
                    r=1;

                    //February non leap year
                else if((dd>=1 && dd<=28) && (mm==2))
                    r=1;

                    //february leap year
                    //YES: Leap Years are any year that can be exactly divided by 4
                    //NO: except if it can be exactly divided by 100 then it isn't 
                    //Yes: except if it can be exactly divided by 400, then it is

                else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0)))
                    r=1;
                else
                    r=0;
            }else{
                r=0;
            }
        }else{
            r=0;
        }    

        return r;
    } 

        

#endif