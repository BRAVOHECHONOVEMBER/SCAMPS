#include "Appointment.h"
#include "../Utils/ClinicException.h"

using namespace std;

namespace SCAPMS {

    // Constructor
    Appointment::Appointment(string id, string pID,
                         string date, string time,
                         string appointmentReason)
    : appointmentID(id),
      patientID(pID),
      appointmentDate(date),
      appointmentTime(time),
      reason(appointmentReason),
      status("Pending") {

        if (appointmentID.empty() || patientID.empty() ||
            appointmentDate.empty() || appointmentTime.empty() ||
            reason.empty()) {

            throw ClinicException("Appointment information cannot be empty.");
        }
    }

    // Getters

    string Appointment::getAppointmentID() const {
        return appointmentID;
    }

    string Appointment::getPatientID() const {
        return patientID;
    }

    string Appointment::getAppointmentDate() const {
        return appointmentDate;
    }

    string Appointment::getAppointmentTime() const {
    return appointmentTime;
    }

    string Appointment::getReason() const {
        return reason;
    }

    string Appointment::getStatus() const {
        return status;
    }

    // Setters

    void Appointment::setAppointmentDate(string newDate) {

        if (newDate.empty()) {
            throw ClinicException("Appointment date cannot be empty.");
        }

        appointmentDate = newDate;
    }

    void Appointment::setAppointmentTime(string newTime) {

        if (newTime.empty()) {
            throw ClinicException("Appointment time cannot be empty.");
        }

        appointmentTime = newTime;
    }

    void Appointment::setReason(string newReason) {

        if (newReason.empty()) {
            throw ClinicException("Appointment reason cannot be empty.");
        }

        reason = newReason;
    }

    // Cancel appointment

    void Appointment::cancelAppointment() {
        status = "Cancelled";
    }

    // Complete appointment

    void Appointment::completeAppointment() {
        status = "Completed";
    }

}