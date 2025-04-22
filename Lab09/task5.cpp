#include <iostream>
#include <string>

class Shipment {
protected:
    std::string trackingNumber;
    double weight;
public:
    Shipment(std::string tn, double w) : trackingNumber(tn), weight(w) {}
    virtual void estimateDeliveryTime() = 0;
    virtual void showDetails() = 0;
    virtual ~Shipment() {}
};

class AirFreight : public Shipment {
public:
    AirFreight(std::string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        std::cout << "Air Freight Estimated Delivery: " << (weight * 0.5) << " hours" << std::endl;
    }
    void showDetails() override {
        std::cout << "Air Freight - Tracking #: " << trackingNumber << ", Weight: " << weight << " kg" << std::endl;
    }
};

class GroundShipment : public Shipment {
public:
    GroundShipment(std::string tn, double w) : Shipment(tn, w) {}
    void estimateDeliveryTime() override {
        std::cout << "Ground Shipment Estimated Delivery: " << (weight * 2.0) << " hours" << std::endl;
    }
    void showDetails() override {
        std::cout << "Ground Shipment - Tracking #: " << trackingNumber << ", Weight: " << weight << " kg" << std::endl;
    }
};

int main() {
    Shipment* s1 = new AirFreight("AIR123", 10.5);
    Shipment* s2 = new GroundShipment("GRD456", 10.5);

    s1->showDetails();
    s1->estimateDeliveryTime();

    s2->showDetails();
    s2->estimateDeliveryTime();

    delete s1;
    delete s2;

    return 0;
}
