#ifndef persona
#define persona

//Define Address structure
    struct _Address_ {
        char* street;
        char* number;
        char* city;
        char* zip;
    };
    typedef struct _Address_ Address;



//Functions for address structure
    
    //Allocation
    Address* newAddress() {

        Address* address = malloc(sizeof(Address));
        assert(address != NULL);

        address->street = NULL;
        address->number = NULL;
        address->city = NULL;
        address->zip = NULL;
        return address;

    }

    // free memory allocation
        Address* delAddress(Address* address) {
            assert(address != NULL);

            if (address->street != NULL) {
            free(address->street);
            }

            if (address->number != NULL) {
            free(address->number);
            }

            if (address->city != NULL) {
            free(address->city);
            }

            if (address->zip != NULL) {
            free(address->zip);
            }

            
            free(address);
        return NULL;
        }

    //Set mutator functions

        void setAddressStreet(Address* address, char* street){
            assert(address!=NULL);
            address->street=street;
        }

        void setAddressNumber(Address* address, char* number){
            assert(address!=NULL);
            address->number=number;
        }

        void setAddressCity(Address* address, char* city){
            assert(address!=NULL);
            address->city=city;
        }

        void setAddressZip(Address* address, char* zip){
            assert(address!=NULL);
            address->zip=zip;
        }

        char* getAddressStreet(Address* address){
            assert(address!=NULL);
            return address->street;
        }

        char* getAddressNumber(Address* address){
            assert(address!=NULL);
            return address->number;
        }

        char* getAddressCity(Address* address){
            assert(address!=NULL);
            return address->city;
        }

        char* getAddressZip(Address* address){
              assert(address!=NULL);
              return address->zip;
        }



//Define person structure
    struct _Person_ {
        char* firstname;
        char* lastname;
        Address* address;
        Date* birthday;
        };
    typedef struct _Person_ Person;



//Functions for person structure

    //Allocation functions

        Person* newPerson(){

            
            Person* person = malloc(sizeof(Person));
            assert(person != NULL);

            person->firstname = NULL;
            person->lastname = NULL;
            person->address = newAddress();
            person->birthday = newDate(0,0,0);
            return person;

        }

    //Free memory allocation 

        Person* delPerson(Person* person) {
            assert(person != NULL);

            if (person->firstname != NULL) {
            free(person->firstname);
            }

            if (person->lastname != NULL) {
            free(person->lastname);
            }

            person->address=delAddress(person->address);

            person->birthday=delDate(person->birthday);

            
            free(person);
        return NULL;
        }
    
    //Mutator functions

        void setPersonFirstname(Person* person, char* firstname){
            assert(person!=NULL);
            person->firstname=firstname;
        }

        char* getPersonFirstname(Person* person){
            assert(person!=NULL);
            return person->firstname;
        }

        void setPersonLastname(Person* person, char* lastname){
            assert(person!=NULL);
            person->lastname=lastname;
        }

        char* getPersonLastname(Person* person){
            assert(person!=NULL);
            return person->lastname;
        }

//Function to find older person

    Person* whoisoldeer(Person* a, Person* b){

    //Compare year of birth;
    if ((a->birthday->year)<(b->birthday->year)){
        return a;
    } else if ((a->birthday->year)>(b->birthday->year))
    {
        return b;
    } else {
        //compare month of birth
        if((a->birthday->month)<(b->birthday->month))
        {
            return a;
        } 
        else if ((a->birthday->month)>(b->birthday->month))
        {
            return b;
        }
        else
        {

            if((a->birthday->day)<(b->birthday->day)){
                return a;
            } else if ((a->birthday->day)>(b->birthday->day)){
                return b;
            } else {

                return NULL;
            }

        }
        
    }

}


#endif