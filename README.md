### Basic Structure of our shell
 - If user enters more than one commands, such as "ls ; pwd" or "emacs& emacs -nw&", the program loops to finish each commands separately
 - Parse the symbol '&' separately to decide whether the current job is foreground job or background job before executing
 - A main loop that never stops looping and executing until user types in "exit"

### Fully Implemented features
 - Launching and executing in background and foreground
 - Bring stopped process to background with "bg %<#>" and bring background or stopped process to foreground with "fg %<#>", only "fg" or "bg" will foreground or background the most recent job.
 - Kill processes: "kill -9 %<#>" to kill process with SIGKILL, "kill %<#>" to kill process with SIGTERM
 - Print job list: "jobs" to pring all the current background and stopped jobs

### Limitations
- Cannot kill "sleep" process with SIGTERM when sleep is running in background; for instance "sleep 100 &" cannot be killed with "kill %<index_num>", but can be killed with "kill -9 %<index_num>" (SIGKILL)
- Cannot kill "emacs -nw &" process with SIGTERM when RUNNING IN VALGRIND, but can be killed with "-9" flag (SIGKILL). However when not running in valgrind, "emacs -nw &" can be killed with SIGTERM;
- Atom by default runs in background, thus running Atom in background, the job list does not contains the atom process. 
