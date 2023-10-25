#include<stdio.h>
#include<stdlib.h>
#include<string.h>


# define MemorySize 2048 //2KB


typedef struct {
    char Name[50];
    
}Record;
typedef struct {
     Record* myRecord;
    int recordCount;
    int availableSpace;
    
} Virtualstorage;
void VirtualDisk(Virtualstorage*memory){
    memory-> myRecord = (Record*)malloc(MemorySize);
    memory-> recordCount = 0;
    memory-> availableSpace = MemorySize/ sizeof(Record);

}
void creatRecord(Virtualstorage*memory, const char* Name ){
    if(memory->recordCount< memory->availableSpace){
        Record nameRecord;
        strncpy(nameRecord.Name,Name, sizeof(nameRecord.Name));
        memory->myRecord[memory->recordCount] = nameRecord;
        memory-> recordCount++;
        memory->availableSpace--; 
 
        printf("Record created:  %s\n", Name); 
    }
    else{
        printf("Memory space is full.\n" );
    }
}
void readRecord(Virtualstorage*memory, int index){ 
    if (index >= 0 && index < memory->recordCount) {
        Record* record = &memory->myRecord[index];

        printf("Record at index %d: %s\n",index,record->Name);
    }
    else{
        printf("Record does not exist.\n", index);
    }
     
}

void updateRecord(Virtualstorage*memory, int index, char* newName){
    if(index>=0 && index< memory->recordCount){
        Record* record = &memory->myRecord[index];
        strncpy(record->Name, newName, sizeof(record->Name));
        printf("updated names at index %d: %s\n", index, newName);
    }
    else{
        printf("update failled. %d", index);
    }
    
}

 void valueInMemory(Virtualstorage*memory ){
    for (int i = 0; i < memory->recordCount; i++)
    {
        printf("Record %d: %s\n", i, memory->myRecord[i].Name);

    }

}


int main(){

    Virtualstorage memory;
    VirtualDisk(&memory);

    creatRecord(&memory, "Maryam");
    creatRecord(&memory, "Teslimat");
    creatRecord(&memory,"Joshia");
    creatRecord(&memory, "Lawerence");
    creatRecord(&memory, "Wasilat");
    creatRecord(&memory, "Bola");
    
   
  

    readRecord(&memory,2);
    readRecord(&memory, 8);
    updateRecord(&memory, 0, "Tosin");
    valueInMemory(&memory);

    

    int spaceLeft = memory.availableSpace - memory.recordCount;
    printf("Available memory space is:%dbyte.\n ", spaceLeft);

    if (memory.recordCount >= memory.availableSpace)
    {
        printf("memory space is full. cannot create a new record.\n");
    }

    
    free(memory.myRecord);
    return 0;
}



