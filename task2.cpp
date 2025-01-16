//#include <iostream>
//#include <string>
//using namespace std;
//
//class Disease {
//protected:
//    string name;
//    float infectionRate;
//    float mortalityRate;
//    int duration; // duration in months
//
//public:
//    Disease(string n, float ir, float mr, int d)
//        : name(n), infectionRate(ir), mortalityRate(mr), duration(d) {}
//
//    virtual void progression(int months) 
//    {
//        float progressionFactor = months / static_cast<float>(duration);
//        cout << name << " progression after " << months << " months: "
//            << progressionFactor * 100 << "%.\n";
//    }
//};
//
//class ViralDisease : public Disease {
//private:
//    float viralLoad;
//    float mutationRate;
//
//public:
//    ViralDisease(string n, float ir, float mr, int d, float vl, float mRate)
//        : Disease(n, ir, mr, d), viralLoad(vl), mutationRate(mRate) {}
//
//    void adjustInfectionRate()
//    {
//        infectionRate += infectionRate * (mutationRate / 100);
//        cout << name << " infection rate adjusted due to mutations: " << infectionRate << "%.\n";
//    }
//
//    void progression(int months) override
//    {
//        adjustInfectionRate();
//        Disease::progression(months);
//    }
//};
//
//class BacterialDisease : public Disease {
//private:
//    float antibioticResistance;
//
//public:
//    BacterialDisease(string n, float ir, float mr, int d, float resistance)
//        : Disease(n, ir, mr, d), antibioticResistance(resistance) {}
//
//    void adjustInfectionRate() 
//    {
//        infectionRate -= infectionRate * (antibioticResistance / 100);
//        cout << name << " infection rate adjusted due to antibiotic resistance: " << infectionRate << "%.\n";
//    }
//
//    void progression(int months) override
//    {
//        adjustInfectionRate();
//        Disease::progression(months);
//    }
//};
//
//class TreatmentProtocol {
//protected:
//    float efficacy;
//    float successRate;
//
//public:
//    TreatmentProtocol(float e, float sr) : efficacy(e), successRate(sr) {}
//    virtual void applyTreatment(float& treatmentEfficacy)
//    {
//        treatmentEfficacy *= efficacy / 100;
//        cout << "Treatment applied with efficacy: " << efficacy << "%.\n";
//    }
//};
//
//class Patient {
//protected:
//    string name;
//    int age;
//    Disease* disease;
//    float treatmentEfficacy;
//
//public:
//    Patient(string n, int a, Disease* d, float te)
//        : name(n), age(a), disease(d), treatmentEfficacy(te) {}
//
//    virtual void monitorProgression(int months)
//    {
//        disease->progression(months);
//    }
//};
//
//class TreatedPatient : public Patient, protected TreatmentProtocol
//{
//public:
//    TreatedPatient(string n, int a, Disease* d, float te, float e, float sr)
//        : Patient(n, a, d, te), TreatmentProtocol(e, sr) {}
//
//    void monitorProgression(int months) override
//    {
//        disease->progression(months);
//        applyTreatment(treatmentEfficacy);
//        cout << "Final treatment efficacy after " << months << " months: " << treatmentEfficacy << "%.\n";
//    }
//};
//
//int main()
//{
//    Disease* covid = new ViralDisease("COVID-19", 50, 2.5, 12, 200, 5);
//    Disease* tb = new BacterialDisease("Tuberculosis", 30, 10, 24, 15);
//
//    Patient* patient1 = new TreatedPatient("Alice", 35, covid, 90, 80, 75);
//    Patient* patient2 = new TreatedPatient("Bob", 42, tb, 85, 70, 65);
//
//    patient1->monitorProgression(6);  
//    patient2->monitorProgression(12); 
//
//    delete covid;
//    delete tb;
//    delete patient1;
//    delete patient2;
//
//    return 0;
//}
