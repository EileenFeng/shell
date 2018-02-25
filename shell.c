#include <sys/types>
#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "dlist.h"
#include "job_node.h"
#include "shell.h"
#include "tokenizer.h"

#define SUCCESS 1
#define FAIL 0
#define BUFF_SIZE 5

enum status{background, foreground, suspended};
enum flags{foreground_to_background,
  suspended_to_background,
  background_to_foreground,
  foreground_to_kill,
  exit_shell, shart_background};

sem_t* all;
sem_t* backgroundlist;
sem_t* suspendedlist;

dlist* all_joblist;
dlist* background_joblist;
dlist* suspended_joblist;

int main(int argc, char* argv[]){
  void* shmem_all_joblist = create_shared_memory(sizeof(dlist*));
  void* shmem_background_joblist = create_shared_memory(sizeof(dlist*));
  void* shmem_suspended_joblist = create_shared_memory(sizeof(dlist*));
  memcpy(shmem_all_joblist, (void*)all_joblist, sizeof(all_joblist));
  memcpy(shmem_suspended_joblist,(void*)suspended_joblist,sizeof(suspended_joblist));
  memcpy(shemem_background_joblist,(void*)background_joblist,sizeof(suspended_joblist));
  size_t byte_num = 0;
  size_t buff_size = BUFF_SIZE;
  char* buffer = NULL;
  byte_num = getline(buffer, &buff_size, STDIN_FILENO);
  parse(&buffer, byte_num);
}

int parse(char* buffer, size_t byte_num){
  int i = n = 0;
  if(! byte_num){
    return 0;
  }
  if(strcmp(buffer, "") == 0){
    return 0;
  }
}

void* create_shared_memory(size_t size){
  int protection = PROT_READ | PROT_WRITE;
  int visibility = MAP_ANONYMOUS | MAP_SHARED;
  return mmap(NULL, size, protection, visibility, 0, 0);
}
