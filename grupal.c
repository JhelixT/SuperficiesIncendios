#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct info{
    int pais_id;
    char pais[20];
    int provincia_id;
    char provincia[20];
    int departamento_id;
    char departamento[20];
    float sup_afectada;
    char unidad_medida[3];
    int cant_focos;
    int anio_inicial;
};

int main() {
    setlocale(LC_ALL, "");
    struct info temp;
    struct info* province=(struct info*)malloc(sizeof(struct info));
    if(province==NULL){
        printf("No se pudo reservar la memoria\n");
        exit(1);
    }
    int lineas=0;
    FILE* fp=fopen("./sup_afectada.csv", "r");
    if(fp==NULL){
        printf("No se pudo abrir el archivo\n");
        exit(1);
    }
    fscanf(fp, "%*[^\n]");
    while(fscanf(fp,"%d;%[^;];%d;%[^;];%d;%[^;];%f;%[^;];%d;%d", &temp.pais_id, temp.pais, &temp.provincia_id, temp.provincia, &temp.departamento_id, temp.departamento, &temp.sup_afectada, temp.unidad_medida, &temp.cant_focos, &temp.anio_inicial)==10){
        province=(struct info*)realloc(province, (lineas+1)*sizeof(struct info));
        *(province+lineas)=temp;
        lineas++;
    }
    printf("Archivo Leido\n");
    fclose(fp);
    int i=0;
    for(i=0;i<lineas;i++){
        printf("ID Pais: %d\n", (province+i)->pais_id);
        printf("Pais: %s\n", (province+i)->pais);
        printf("ID Provincia: %d\n", (province+i)->provincia_id);
        printf("Provincia: %s\n", (province+i)->provincia);
        printf("ID Departamento: %d\n", (province+i)->departamento_id);
        printf("Departamento: %s\n", (province+i)->departamento);
        printf("Superficie Afectada: %.2f%s\n", (province+i)->sup_afectada, (province+i)->unidad_medida);
        printf("Cantidad de Focos: %d\n", (province+i)->cant_focos);
        printf("Anio de Inicio: %d\n", (province+i)->anio_inicial);
        printf("\n");
    }
    return 0;
}