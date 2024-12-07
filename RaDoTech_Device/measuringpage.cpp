#include "measuringpage.h"
#include "ui_measuringpage.h"
#include <cmath>
MeasuringPage::MeasuringPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MeasuringPage)
{

    ui->setupUi(this);
    connect(ui->NextButton, SIGNAL(released()), this, SLOT(nextButtonisClicked()));;
    connect(ui->saveButton, SIGNAL(released()), this, SLOT(saveButtonisClicked()));;
    connect(ui->backButton, &QPushButton::clicked, this, [=]() {emit backButtonClicked();});
    connect(ui->saveButton, &QPushButton::clicked, this, [=]() {
        if(index<24){return;}
        index = 1;
        emit saveButtonClicked();});
    connect(ui->backButton, SIGNAL(released()), this, SLOT(backButtonisClicked()));;

    ui->textBrowser->insertPlainText("Place device on the far left of your wrist (right hand, palm side) \n");

    finished = false;
    index=1;
}

MeasuringPage::~MeasuringPage()
{
    delete ui;
}

void MeasuringPage::nextButtonisClicked(){
    performScan();
    index++;

}

void MeasuringPage::backButtonisClicked(){
    ui->textBrowser->setText("");
    index = 1;
}
int MeasuringPage::checkOtherSide(string x,int y){
    srand(time(0));
    int result=0;
    if(x=="H1"){
       result=rand()%190 +1;
       if(y>=85){ // above normal
           while(result<85){
               result = rand()%100 +1;
           }
           analysis["Lung"] = "above normal";
       }else if(y<=55){ // below normal
           while(result>55){
               result = rand()%100 +1;
           }
           analysis["Lung"] = "below normal";
       } else{ // normal
           while(result>85 || result<55){
               result = rand()%100 +1;
           }
           analysis["Lung"] = "normal";
       }
    }else if(x=="H2"){
        result=rand()%170 +1;
        if(y>=75){ // above normal
            while(result<75){
                result = rand()%100 +1;
            }
            analysis["Pericardium"] = "above normal";
        }else if(y<=53){ // below normal
            while(result>53){
                result = rand()%100 +1;
            }
            analysis["Pericardium"] = "below normal";
        } else{ // normal
            while(result>75 || result<53){
                result = rand()%100 +1;
            }
            analysis["Pericardium"] = "normal";
        }
     }else if(x=="H3"){
        result=rand()%140 +1;
        if(y>=65){ // above normal
            while(result<65){
                result = rand()%100 +1;
            }
            analysis["Heart"] = "above normal";

        }else if(y<=43){ // below normal
            while(result>43){
                result = rand()%100 +1;
            }
            analysis["Heart"] = "below normal";
        } else{ // normal
            while(result>65 || result<43){
                result = rand()%100 +1;
            }
            analysis["Heart"] = "normal";
        }
     }else if(x=="H4"){
        result=rand()%170 +1;
        if(y>=78){ // above normal
            while(result<78){
                result = rand()%100 +1;
            }
            analysis["Small intestine"] = "above normal";
        }else if(y<=53){ // below normal
            while(result>53){
                result = rand()%100 +1;
            }
            analysis["Small intestine"] = "below normal";

        } else{ // normal
            while(result>78 || result<53){
                result = rand()%100 +1;
            }
            analysis["Small intestine"] = "normal";

        }
     }else if(x=="H5"){
        result=rand()%200 +1;
        if(y>=90){ // above normal
            while(result<90){
                result = rand()%100 +1;
            }
            analysis["Lymph"] = "above normal";
        }else if(y<=60){ // below normal
            while(result>60){
                result = rand()%100 +1;
            }
            analysis["Lymph"] = "below normal";

        } else{ // normal
            while(result>90 || result<60){
                result = rand()%100 +1;
            }
            analysis["Lymph"] = "normal";

        }
     }else if(x=="H6"){
        result=rand()%200 +1;
        if(y>=98){ // above normal
            while(result<98){
                result = rand()%100 +1;
            }
            analysis["Large intestine"] = "above normal";
        }else if(y<=61){ // below normal
            while(result>61){
                result = rand()%100 +1;
            }
            analysis["Large intestine"] = "below normal";
        } else{ // normal
            while(result>98 || result<61){
                result = rand()%100 +1;
            }
            analysis["Large intestine"] = "normal";

        }
     }if(x=="F1"){
        result=rand()%160 +1;
        if(y>=70){ // above normal
            while(result<70){
                result = rand()%100 +1;
            }
            analysis["Pancreas"] = "above normal";
        }else if(y<=47){ // below normal
            while(result>47){
                result = rand()%100 +1;
            }
            analysis["Pancreas"] = "below normal";

        } else{ // normal
            while(result>70 || result<47){
                result = rand()%100 +1;
            }
            analysis["Pancreas"] = "normal";
        }
     }else if(x=="F2"){
        result=rand()%130 +1;
         if(y>=57){ // above normal
             while(result<57){
                 result = rand()%100 +1;
             }
             analysis["Liver"] = "above normal";

         }else if(y<=40){ // below normal
             while(result>40){
                 result = rand()%100 +1;
             }
             analysis["Liver"] = "below normal";

         } else{ // normal
             while(result>57 || result<40){
                 result = rand()%100 +1;
             }
             analysis["Liver"] = "normal";

         }
      }else if(x=="F3"){
        result=rand()%150 +1;
         if(y>=65){ // above normal
             while(result<65){
                 result = rand()%100 +1;
             }
             analysis["Kidney"] = "above normal";

         }else if(y<=45){ // below normal
             while(result>45){
                 result = rand()%100 +1;
             }
             analysis["Kidney"] = "below normal";

         } else{ // normal
             while(result>65 || result<45){
                 result = rand()%100 +1;
             }
             analysis["Kidney"] = "normal";

         }
      }else if(x=="F4"){
        result=rand()%150 +1;
         if(y>=65){ // above normal
             while(result<65){
                 result = rand()%100 +1;
             }
             analysis["Bladder"] = "above normal";

         }else if(y<=45){ // below normal
             while(result>45){
                 result = rand()%100 +1;
             }
             analysis["Bladder"] = "below normal";

         } else{ // normal
             while(result>65 || result<45){
                 result = rand()%100 +1;
             }
             analysis["Bladder"] = "normal";

         }
      }else if(x=="F5"){
        result=rand()%130 +1;
         if(y>=58){ // above normal
             while(result<58){
                 result = rand()%100 +1;
             }
             analysis["Gall bladder"] = "above normal";

         }else if(y<=40){ // below normal
             while(result>40){
                 result = rand()%100 +1;
             }
             analysis["Gall bladder"] = "below normal";

         } else{ // normal
             while(result>58 || result<40){
                 result = rand()%100 +1;
             }
             analysis["Gall bladder"] = "normal";

         }
      }else if(x=="F6"){
        result=rand()%150 +1;
         if(y>=65){ // above normal
             while(result<65){
                 result = rand()%100 +1;
             }
             analysis["Stomach"] = "above normal";

         }else if(y<=43){ // below normal
             while(result>43){
                 result = rand()%100 +1;
             }
             analysis["Stomach"] = "below normal";

         } else{ // normal
             while(result>65 || result<43){
                 result = rand()%100 +1;
             }
             analysis["Stomach"] = "normal";

         }
      }
    return result;
}
void MeasuringPage::saveButtonisClicked(){
    if(index<24){return;}
    ui->textBrowser->setText("");

    emit sendReadingToUser(readings, analysis);
}

void MeasuringPage::performScan(){
    srand(time(0));
    if(index == 1){

        readings["H1"] = rand()%190 +1;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["H1"]) + "\n");
        ui->textBrowser->insertPlainText("Place device at the center of the wrist (right hand, palm side) \n");

    } else if(index == 2){

        readings["H2"] = rand()%170 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["H2"]) + "\n");
        ui->textBrowser->insertPlainText("Place device on the far right of your wrist (right hand) \n");

    }else if(index == 3){

        readings["H3"] = rand()%140 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["H3"]) + "\n");
        ui->textBrowser->insertPlainText("Place device on the pinky side of your hand (right hand) \n");

    }else if(index == 4){

        readings["H4"] = rand()%170 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["H4"]) + "\n");
        ui->textBrowser->insertPlainText("Place device at the center of the wrist (right hand, dorsal side) \n");

    }else if(index == 5){

        readings["H5"] = rand()%200 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["H5"]) + "\n");
        ui->textBrowser->insertPlainText("Place device on the far left of your wrist (right hand, dorsal side) \n");

    }else if(index == 6){

        readings["H6"] = rand()%200 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["H6"]) + "\n");
        ui->textBrowser->insertPlainText("Place device  the indentation at the back inner side of the first metatarsal"
                                         "bone head (right foot) \n");

    }if(index == 7){

        readings["F1"] = rand()%160 +1;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["F1"]) + "\n");
        ui->textBrowser->insertPlainText("Place device between the bones of the first and second toe (right foot) \n");

    } else if(index == 8){

        readings["F2"] = rand()%130 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["F2"]) + "\n");
        ui->textBrowser->insertPlainText("Place device between the inner"
                                         "ankle bone and the point of the heel (right foot) \n");

    }else if(index == 9){

        readings["F3"] = rand()%150 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["F3"]) + "\n");
        ui->textBrowser->insertPlainText("Place device outer side of the fifth metatarsal bone"
                                         "head (right foot) \n");

    }else if(index == 10){

        readings["F4"] = rand()%150 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["F4"]) + "\n");
        ui->textBrowser->insertPlainText("Place device  between the outer an"
                                         "kle bone and the fourth toe (right foot) \n");

    }else if(index == 11){

        readings["F5"] = rand()%130 +1;;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["F5"]) + "\n");
        ui->textBrowser->insertPlainText("Place device on the center of the foot (right foot) \n");

    }else if(index == 12){

        readings["F6"] = rand()%150 +1;
        ui->textBrowser->insertPlainText("Current point: " + QString::number(readings["F6"]) + "\n");
        ui->textBrowser->insertPlainText("Place device on the far left of your wrist (left hand, palm side) \n");

    }if(index == 13){
        int tempvalue = checkOtherSide("H1", readings["H1"]);
        readings["H1"] = ceil((checkOtherSide("H1", readings["H1"])+ readings["H1"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device at the center of the wrist (left hand, palm side) \n");

    } else if(index == 14){

        int tempvalue = checkOtherSide("H2", readings["H2"]);
        readings["H2"] = ceil((checkOtherSide("H2", readings["H2"])+ readings["H2"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device on the far right of your wrist (left hand) \n");

    }else if(index == 15){

        int tempvalue = checkOtherSide("H3", readings["H3"]);
        readings["H3"] = ceil((checkOtherSide("H3", readings["H3"])+ readings["H3"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device on the pinky side of your hand (left hand) \n");

    }else if(index == 16){

        int tempvalue = checkOtherSide("H4", readings["H4"]);
        readings["H4"] = ceil((checkOtherSide("H4", readings["H4"])+ readings["H4"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device at the center of the wrist (left hand, dorsal side) \n");

    }else if(index == 17){
        int tempvalue = checkOtherSide("H5", readings["H5"]);
        readings["H5"] = ceil((checkOtherSide("H5", readings["H5"])+ readings["H5"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device on the far left of your wrist (left hand, dorsal side) \n");

    }else if(index == 18){

        int tempvalue = checkOtherSide("H6", readings["H6"]);
        readings["H6"] = ceil((checkOtherSide("H6", readings["H6"])+ readings["H6"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device  the indentation at the back inner side of the first metatarsal"
                                         "bone head (left foot) \n");

    }if(index == 19){

        int tempvalue = checkOtherSide("F1", readings["F1"]);
        readings["F1"] = ceil((checkOtherSide("F1", readings["F1"])+ readings["F1"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device between the bones of the first and second toe (left foot) \n");

    } else if(index == 20){

        int tempvalue = checkOtherSide("F2", readings["F2"]);
        readings["F2"] = ceil((checkOtherSide("F2", readings["F2"])+ readings["F2"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device between the inner"
                                         "ankle bone and the point of the heel (left foot) \n");

    }else if(index == 21){

        int tempvalue = checkOtherSide("F3", readings["F3"]);
        readings["F3"] = ceil((checkOtherSide("F3", readings["F3"])+ readings["F3"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device outer side of the fifth metatarsal bone"
                                         "head (left foot) \n");

    }else if(index == 22){

        int tempvalue = checkOtherSide("F4", readings["F4"]);
        readings["F4"] = ceil((checkOtherSide("F4", readings["F4"])+ readings["F4"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device  between the outer an"
                                         "kle bone and the fourth toe (left foot) \n");

    }else if(index == 23){

        int tempvalue = checkOtherSide("F5", readings["F5"]);
        readings["F5"] = ceil((checkOtherSide("F5", readings["F5"])+ readings["F5"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Place device on the center of the foot (left foot) \n");

    }else if(index == 24){

        int tempvalue = checkOtherSide("F6", readings["F6"]);
        readings["F6"] = ceil((checkOtherSide("F6", readings["F6"])+ readings["F6"])/2);
        ui->textBrowser->insertPlainText("Current point: " + QString::number(tempvalue) + "\n");
        ui->textBrowser->insertPlainText("Don't forget to save \n");
    }
}
