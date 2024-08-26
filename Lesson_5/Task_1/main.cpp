#include <iostream>
#include <string>
#include <vector>

using namespace std;

// base class
class automobile {
private:
    string manufacturer;
protected:
    float price;
    string type;
public:
    // constructor
    automobile(string manu, double p, string t) : manufacturer(manu), price(p), type(t) {}

    // getters and setters for the producer
    string getManufacturer() const { return manufacturer; }
    void setManufacturer(const string& manu) { manufacturer = manu; }

    // getters and setters for price
    double getPrice() const { return price; }
    void setPrice(double p) { price = p; }

    // getters and setters for type
    string getType() const { return type; }
    void setType(const string& t) { type = t; }

    // destructor
    virtual ~automobile() {}

    // function for displaying information
    virtual void printInfo() const {
        cout << "Manufacturer: " << manufacturer << ", Price: $" << price << ", Type: " << type << endl;
    }
};

// child class
class Sedan : public automobile {
private:
    string model;
    int seats;
    string color;
public:
    // constructor
    Sedan(string manu, double p, string t, string m, int s, string c)
        : automobile(manu, p, t), model(m), seats(s), color(c) {}

    // getters and setters for the model range
    string getModel() const { return model; }
    void setModel(const string& m) { model = m; }

    // getters and setters for the number of seats
    int getSeats() const { return seats; }
    void setSeats(int s) { seats = s; }

    // getters and setters for the color
    string getColor() const { return color; }
    void setColor(const string& c) { color = c; }

    // overriding the function to display information
    void printInfo() const override {
        automobile::printInfo();
        cout << "Model: " << model << ", Seats: " << seats << ", Color: " << color << endl;
    }
};

int main() {
    vector<automobile*> cars;

    // cars
    cars.push_back(new Sedan("Toyota", 20000, "Sedan", "Camry", 5, "Red"));
    cars.push_back(new Sedan("Ford", 25000, "Sedan", "Fusion", 5, "Blue"));
    cars.push_back(new Sedan("BMW", 50000, "Sedan", "3 Series", 5, "Black"));

    // filtration
    string desiredType, desiredManufacturer;
    double maxPrice;

    cout << "Enter desired car type (e.g., Sedan): ";
    cin >> desiredType;
    cout << "Enter desired manufacturer (e.g., Toyota): ";
    cin >> desiredManufacturer;
    cout << "Enter maximum price: $";
    cin >> maxPrice;

    cout << "\nAvailable cars:\n";
    for (auto car : cars) {
        if (car->getType() == desiredType && car->getManufacturer() == desiredManufacturer && car->getPrice() <= maxPrice) {
            car->printInfo();
            cout << endl;
        }
    }

    // clearing memory
    for (auto car : cars) {
        delete car;
    }

    return 0;
}
