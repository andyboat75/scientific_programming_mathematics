#include "university.hpp" 

int main(){
    University KNUST;
    KNUST.setCity("Kumasi");
    KNUST.setName("Kwame Nkrumah University of Science and Technology.");
    KNUST.setNum_students(30);

    cout<<"Name: "<<KNUST.getName()<<endl;
    cout<<"City: "<<KNUST.getCity()<<endl;
    cout<<"Number of Students: "<<KNUST.getNum_students()<<endl;

    KNUST.graduate();

    cout<<"Number of Students after graduation: "<<KNUST.getNum_students()<<endl;

    KNUST.newStudent();

    cout<<"Number of Students after admission: "<<KNUST.getNum_students()<<endl;

    return 0;
}