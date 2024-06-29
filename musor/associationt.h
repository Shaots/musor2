#ifndef TEST_ASSOCIATIONT_H
#define TEST_ASSOCIATIONT_H


#include <iostream>
#include <vector>

class Doctor;

class Patient {
    friend class Doctor;

public:
    explicit Patient(std::string name) : m_name(name) {}

    friend std::ostream& operator<<(std::ostream& out, const Patient& pat);

    std::string getName() const { return m_name; }

private:
    void addDoctor(Doctor* doc);

private:
    std::vector<Doctor*> m_doctor;
    std::string m_name;
};

class Doctor {
public:
    explicit Doctor(std::string name) : m_name(name) {}

    void addPatient(Patient* pat) {
        m_patient.push_back(pat);
        pat->addDoctor(this);
    }

    friend std::ostream& operator<<(std::ostream& out, const Doctor& doc) {
        unsigned int length = doc.m_patient.size();
        if (length == 0) {
            out << doc.m_name << " has no patients right now";
            return out;
        }
        out << doc.m_name << " is seeing patients: ";
        for (unsigned int count = 0; count < length; ++count)
            out << doc.m_patient[count]->getName() << ' ';
        return out;
    }

    std::string getName() const { return m_name; }

private:
    std::vector<Patient*> m_patient;
    std::string m_name;
};

#endif //TEST_ASSOCIATIONT_H
