# SOLID PRINCIPLES

The SOLID principles are a set of design principles aimed at making software designs more understandable, flexible, and maintainable. The principles are:

1. **Single Responsibility Principle (SRP)**
2. **Open/Closed Principle (OCP)**
3. **Liskov Substitution Principle (LSP)**
4. **Interface Segregation Principle (ISP)**
5. **Dependency Inversion Principle (DIP)**

# 1. Single Responsibility [S]

The Single Responsibility Principle states that a class should have only one reason to change, meaning it should have only one responsibility or job. This principle helps to achieve a more modular and maintainable codebase.

##### Benefits :

* Lower Test Cases
* Lower Coupling , lower dependencies
* Easier to understand
* Organized

**EXAMPLE:**

```
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
```


# 2. OPEN-CLOSED [O]

Software entities (classes, modules, functions, etc.) should be open for extension but closed for modification. This means you should be able to add new functionality without changing existing code.

```
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
        CustomerDB(){};
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
        DBDisplay(const CustomerDB  &obj):customer(obj){        };

        void display()
        {   

              for (const auto& db :  customer.getterDB()) {
            std::cout << "Customer: " << db.getter() << std::endl;
        }  
        }

    private: 
       const   CustomerDB customer;
};
```


# 3. Liskov Substitution

Subtypes must be substitutable for their base types without altering the correctness of the program. This means objects of a derived class should be able to replace objects of the base class without affecting the functionality.

```
Parent *ptr= new Parent()
Parent *ptr= new Child()
```

```
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

```


# 4. Interface Segregation

Clients should not be forced to depend on interfaces they do not use. This means it's better to have many specific interfaces rather than a single, general-purpose interface.


# 5. Dependency Inversion

High-level modules should not depend on low-level modules. Both should depend on abstractions (e.g., interfaces). Additionally, abstractions should not depend on details. Details should depend on abstractions.2
