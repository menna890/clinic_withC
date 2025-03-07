#include "doctors.h"
int choice;
 int idDr, idPatient, idAppointment, spec,IDapp,idDr,times;
 char name[20],namespec[20],nameapp[20];
void admin (){
                 
                while(1){
                printf("\n1. Add Doctor\n2. Delete Doctor\n3. View Specializations\nEnter 0 to Exist.");
                scanf("%d", &choice); 
                switch (choice) {
                    case 1:
                        print_info_spcial(1);
                        print_info_spcial(2);
                        print_info_spcial(3);
                        printf("Enter Doctor ID of Doctor :\n");
                        scanf("%d", &idDr);
                        
                        printf("Enter Doctor Name :\n");
                        scanf("%s", name);
                        
                        printf("Enter Doctor Specialization ID:\n");
                        scanf("%d", &spec, namespec);
                        
                        printf("Enter Doctor Specialization:\n");
                        scanf("%s", namespec);
                        add_dr(idDr, name, spec, name);
                        // Assuming name is used for both name and specialization
                        printf("\nEnter the day:");
                        scanf("%s", nameapp);
                        printf("\nEnter the time: ");
                        scanf("%.2f", &times);
                        printf("Enter the ID of Appointment:\n");
                        scanf("%s",& IDapp);
                        add_appointment(IDapp,idDr,nameapp,times);
                        break;
                    case 2:
                        printf("Enter Doctor number to delete:\n");
                        scanf("%d", &idDr);
                        delete_accountDR(idDr);
                        break;
                    case 3:
                        print_info_spcial(1); // Example to print all specializations
                        print_info_spcial(2);
                        print_info_spcial(3);
                        break;
                    default:
                        //printf("Invalid choice.\n");
                        break;
                }
                   if (choice==0){
                       break;
                   }
                    
                }
        
}