#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "appoint.h"
#pragma once
void print_info_appo(DR* DRdr){
    if(DRdr->appointments==NULL){
        printf("there is no appointments here");
    }
    else{
        printf("the appointments : \n%d_%s\t %.2f AM",DRdr ->appointments->idapp,DRdr ->appointments->name,DRdr ->appointments->times);
        app *last=DRdr ->appointments;
        while(last ->nx!=NULL){
            printf("\n%d_%s\t%.2fAM",last->nx->idapp,last->nx->name,last->nx->times);
            last=last ->nx;        }
            }
}
void print_info_dr(int iddr){
    DR*tempdr=(DR*)search_dr(iddr);
    printf("\n%d_the name of ductor : %s \n",tempdr->ID,tempdr->name);
    printf("the specialization :%s\n",tempdr->specialization);
    print_info_appo(tempdr);
}
void add_appointment(int IDp,int ID_drrr, const char namep[20],float times);
void print_info_spcial(int idspecial){
    if(list_dr ->id_special==idspecial){
        print_info_dr(list_dr ->ID);
    }
     DR * last =list_dr;
        while(last -> nx!=NULL){
            if(last -> nx->id_special!= idspecial){
            last =last ->nx;}
            else{
                printf("\n");
            print_info_dr(last->nx ->ID);
            last =last ->nx;
            continue;  }
    }
    
}
void delete_appointmentfromdr(int id_App,int iddr){
    DR *tempdr =(DR *)search_dr(iddr);
    if (tempdr->appointments->idapp==id_App){
        if(tempdr->appointments->nx==NULL){
        tempdr->appointments=NULL;}
        else{
        tempdr->appointments= tempdr->appointments->nx;
    }
        
    }
    else{
        app * last =tempdr->appointments;
        while(last->nx->idapp!=id_App){
            last=last->nx;
        }
        
        if(last->nx->nx==NULL){
        last->nx=NULL;}
        else{
        //last= last->nx->nx;
        last->nx= last->nx->nx;
            
        }
        
    //    last->nx=last->nx->nx;
      //  last->nx->nx=NULL;
    }
    }
app* search_Appointment(int iddr,int id_App){
    DR* tempdr=(DR*)search_dr(iddr);
    if(tempdr->appointments->idapp==id_App){
        return tempdr->appointments;}
    else{
        app * last=tempdr ->appointments;
        while(last -> nx->idapp!=id_App){
            last=last ->nx;
        }
        return last ->nx;
    }}    
void delete_accountDR(int idpat){
    DR* temppat=(DR*)search_dr(idpat);
    if (list_dr->ID==temppat->ID){
        DR* delete=list_dr;
        list_dr=list_dr ->nx;
        free(delete);}
    else{
        DR* last=list_dr;
        while(last->nx->ID!=idpat){
            last=last->nx;
        }
        DR* delete=last->nx;
        last->nx=last->nx->nx;
        free(delete);
    }
}    
