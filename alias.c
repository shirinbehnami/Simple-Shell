#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MaxSize 307


typedef struct Node{
	char* key;
	char* value;
	struct Node* next;

} Node;



Node* hash_table[MaxSize];

//initale the hash table
Node** get_table(){

	return hash_table;
}

//creating the key hash by multiplying the char index by the ascii value of the char
int hash(char* key){
	int hash_value = 0;
	for(int i=0;i<strlen(key);i++){
		hash_value += key[i] * i+1;
	}
	
	return hash_value%MaxSize;

}




//add a new node to the map
void insert(Node** hash_table,char* key, char* value){
	int index = hash(key);	//getting the hash of the key

	//creating the node for the key/value pair
	Node* node = (Node*)malloc(sizeof(Node)); 
	node->key = key;
	node->value = value;
	node->next = NULL;
	
	//insert the pair into the table if the index is empty(no collision)
	if(hash_table[index]==NULL){
		hash_table[index] = node;
	}
	//if the collision occurs we store all the values with same hash key in a linked list
	else{
		Node* current = hash_table[index];
		Node* last = NULL;
		while(current->next!=NULL){
			current = current->next;
		}
		current->next = node;

	}
}


//its calculate the hash of the key and search for it in the linked list
char* get(Node** hash_table,char* key){
	int index = hash(key);
	
	Node* current = hash_table[index];
	while(current!=NULL){
		if(strcmp(current->key,key)==0)
			return current->value;

		current = current->next;
	}
	//The node doesn't exist
	return NULL;

}


//remove a node from the map
void removeKey(Node** hash_table,char* key){
	int index = hash(key);

	Node* current = hash_table[index];
	Node* last = NULL;
	while(current!=NULL){
		if(strcmp(current->key,key)==0){
			//the list has only one value
			if(last==NULL)
				hash_table[index] = current->next;
		
		
			else
				last->next = current->next;
			
			free(current);
			return;
		}
		last = current;
		current = current->next;
	}


}




int aliasCommand(char** args,int command){

	//printf("%s\t\t\t\n",args[0]);
	
	//printf("%d",strcmp(args[0],"alias"));

//	char *equalSign = strchr(str, '=');

	//if(strcmp(args[0],"lias")){
//	if(equalSign!=NULL){
	if(command==1){
		if(sizeof(args)/sizeof(args[0])!=2){
			printf("%d\n",sizeof(args)/sizeof(args[0]));
			printf("%s\t%s\t%s\t%s\n",args[0],args[1],args[2],args[3]);
			printf("Wrong syntax\nto create an alias use this format:  alias alias_name=\"command\"\n");
		}
		  		
		else{
			insert(get_table() ,args[1], args[2]);
		}


		printf("%s\t\t\t%s\t\t\t%s\n",args[0],args[1],args[2]);
		insert(get_table(),args[1],args[2]);
		printf("%s\n",get(get_table(),args[1]));
	}
	
	
	//elseif(strcmp(args[0],"nalias")){
	else{
	/*
		if(sizeof(args)/sizeof(args[0])!=2){
			printf("Wrong syntax\nto remove an alias use this format: unaliase alias_namei\n");
			printf("%s\t\t\t%s\t\t\t%s",args[0],args[1],args[2]);
		}
		else{
			removeKey(get_table(),args[1]);
		}	
		*/
		removeKey(get_table(),args[1]);
	}
	

	return 0;
}


                                 




