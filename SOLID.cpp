#include <iostream>
#include <vector>
#include <string>
#include <memory>


class Customer
{   
    /*THIS CLASS ONLY HAVE ONE RESPONSIBILITY*/
    public:

        Customer(){}        
        explicit Customer(std::string name1):name(name1){
                        std::cout << "Constructor" << std::endl;

        };

        void setter(std::string name1) 
        {
            name=name1;
        }
        std::string getter() const
        {
            return name;
        }

        virtual~Customer(){
            std::cout << "Destructor" << std::endl;
        };

    private:

        std::string name;

};

/*THIS INTERFACE ONLY HAVE ONE RESPONSIBILITY , AND CLOSED FOR MODIFICATION*/

class ICustomerDB 
{

    public:

    virtual  void addCustomer(const Customer &obj)=0;
    virtual ~ICustomerDB()=default;

};
class CustomerDB  : public ICustomerDB
{   
    public:
        CustomerDB(){
        };


        void addCustomer(const Customer &obj) 
        {
            customerDB.push_back(obj);
        }   
        
  
        std::vector<Customer> getterDB() const
        {

            return customerDB;
        }



    private:
            std::vector<Customer> customerDB;

};


/* ADDING NEW EXTENSIONS FOR THE MODULE / WITHOUT MODIFYING*/

class IDataDisplay 
{

    public:

    virtual  void display(const Customer &obj)=0;
    virtual ~IDataDisplay()=default;

};
class DBDisplay 
{

    public:

        DBDisplay(const CustomerDB  &obj):customer(obj){

        };


        void display()
        {   

              for (const auto& db :  customer.getterDB()) {
            std::cout << "Customer: " << db.getter() << std::endl;
        }  
        }

    private: 

       const   CustomerDB customer;


};


class CustomerAbilities 
{
    public:
    virtual void smoke()=0;
    virtual ~CustomerAbilities(){};
};

/*SUB CLASS CAN SUBSTITUTE THEIR PARENT OBJECT*/
class AdultCustomer : public CustomerAbilities
{
    public:
    AdultCustomer()=default;
    void smoke()
    {
        std::cout << "smoking" << std::endl;
    }
    ~AdultCustomer()=default;
};
class TeenCustomer : public CustomerAbilities
{
    public:
    TeenCustomer()=default;
    void smoke()
    {
        std::cout << "Cant smoke" << std::endl;
    }
    ~TeenCustomer()=default;
};









int main()
{
  
    Customer c1("som3a");
    Customer c2("som1113a");
    CustomerDB db1;
    db1.addCustomer(c1);
    db1.addCustomer(c2);

    DBDisplay ddb1(db1);
    ddb1.display();
    
    CustomerAbilities *obj=new AdultCustomer();
        CustomerAbilities *obj2=new TeenCustomer();
    obj2->smoke();
    delete obj;
  return 0;
}