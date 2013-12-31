#define INCL_PM
#define INCL_DOS
#define INCL_ERRORS
#define INCL_DOSMEMMGR

#define INCL_DOSPROCESS
#define INCL_DOSMISC
#define INCL_KBD
#define INCL_VIO

/***********MAKROS*****************/

#define YELLOW()     printf("\033[33m")       /*Gelber Ausdruck*/
#define F_NORM()     printf("\033[37m")       /*Normaler Ausdruck*/
#define REVERSE()    printf("\033[7m")        /* Schwarz auf Weiss */
#define NORMAL()     printf("\033[0m")         /*Darstellung weiss auf schwarz */
#define POS(x,y)     printf("\033[%d;%dH", x, y)
#define CLEAR()      printf("\033[2J")                   /*Lîschen des Monitors*/
#define SAVE()       printf("\033[s")
#define RESTORE()    printf("\033[u")
#define HEADER()     printf("  Datensatz eingeben \n")
#define MESSAGE()    printf("Weiter mit <Enter>. \n")
/* #define _F_DEBUG  */


#include<conio.h>
#include<ctype.h>
#include<direct.h>
#include<errno.h>
#include<fcntl.h>
#include<io.h>
#include<malloc.h>
#include<os2.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>



int bann_Domain(char *Domain, int bann_time);
int bann_sender(char *sender, int bann_time);
int bann_IP(ULONG IP, int bann_time);
int check_empty_body(char *body, int len_body, char *boundary_ptr, int empty_body);
int check_ini(int num_file_ini, char *file_buffer_ini, char *entry);
char* check_ini_P(int num_file_ini, char *file_buffer_ini, char *entry);
int checkrelation(char *file_buffer_relation_file, int num_file_relationfile, char *from_mailadress,int len_from_mailadress, char *to_ptr);
int check_user_logic(char* buffer, int buffer_len, char* adress, int size);
int comp_domain(char *domain, char *domain1);
int correct_ini(int file_handle_ini, char* file_buffer_ini, char *file);
int cut_out_major_list_lines(long begin_cut_out, int argc, char *argv1, char *argv2, char *log_path_error, char *file_buffer_messagefile, int num_file_messagefile, char *body);
int decode(char *inbuffer, int len_buffer, char *outbuffer, int *size_out_buffer );
void encode(char *inbuffer, char *outbuffer, int linesize, int buffer_size );
char* extract_from(char *from, char *from_name_ptr, char *sender);
char* f_memmove(char *dest, char *source, int size);
int f_strlen(char *buffer);
char* f_strmove(char *dest, char *source, int size);
char* get_from_mailadress(char* begin_line);
ULONG ip_2_Ulong(char *ipadress, char *domain);
char* stristr(char* string, int string_len, char* substring, int substring_len);
char* f_strstr(char* string, int string_len, char* substring, int substring_len);
char* search_for_key(char* body, int temp_len, char* key_ptr, int len_key);
int test_from_name(char* subject_line, int len_line, char* subject, int len_sub, int value);
int test_mail_addres(char* subject_line, int len_line, char* subject, int len_sub, int value);
int test_ip_link(char* body, int rest);
int test_subject(char* subject_line, int len_line, char* subject, int len_sub, int value);
int test_of_empty_subject(char *subject, int empty_subject, int min_subject);
int track_mail(ULONG IP, char *Domain, char *sender, int bann_time, int bombing_amount, int bombing_time);
char* tune_subject(char* subject);
char *ulong_2_ip(ULONG IP, char *whole);


int errortracking = 1;
char log_path[_MAX_PATH] = {'\0'};
char log_path_error[_MAX_PATH] = {'\0'};
char *log_PTR = NULL;
int logging = 0;
struct tm *newtime;



int main (int argc, char *argv[])
    {

    FILE *stream = NULL;
    FILE *stream1 = NULL;
    FILE *error_stream = NULL;

    char drive[_MAX_DRIVE] = {'\0'};
    char dir[_MAX_DIR] = {'\0'};
    char fname[_MAX_FNAME] = {'\0'};
    char ext[_MAX_EXT] = {'\0'};

    char adress_path[_MAX_PATH] = {'\0'};
    char *adress = NULL;
    char *argv2 = NULL;
    int bann_time = 24;
    int base64 = 0;
    char *base64_ptr = NULL;
    char *bcc_ptr = NULL;
    long begin_cut_out = 0;
    char *begin_line = NULL;
    int blacklist = 0;
    int blacklist_temp = 0;
    int blacklist_temp_dat = 0;
    int blacklist_dat = 0;
    char *body = NULL;
    char body_file_path[_MAX_PATH] = {'\0'};
    char *body_file = NULL;
    int body_scan = 0;
    int body_scan_multipart = 0;
    int body_scan_size = 4;
    int body_size = 0;
    int bombing_amount = 10;
    int bombing_time = 1;
    int boundary = 0;
    char *boundary_ptr = NULL;
    int buffer_size_address = 0;
    int buffer_size_blacklist = 0;
    int buffer_size_blacklist_dat = 0;
    int buffer_size_blacklist_temp = 0;
    int buffer_size_blacklist_temp_dat = 0;
    int debug_crash = 0;
    int file_size_body = 0;
    int buffer_size_body = 0;
    int buffer_size_ini = 0;
    int buffer_size_messagefile = 0;
    int buffer_size_namefile = 0;
    int buffer_size_name_from = 0;
    int buffer_size_relationfile = 0;
    int buffer_size_subject = 0;
    int buffer_size_subject_dat = 0;
    char *cc_ptr = NULL;
    char character = 0;
    int check_relation = 0;
    int content_transfer_encoding = 0;
    int content_type = 0;
    char *content_type_ptr = NULL;
    int copy_file = 0;
    int counter = 0;
    char *date_ptr = NULL;
    char domain_buffer[1024] = {'\0'};
    char *domain = NULL;
    int empty_body = 0;
    int empty_subject = 0;
    char *end = NULL;
    char *end_cc_ptr = NULL;
    char *end_bcc_ptr = NULL;
    int end_decode = 0;
    char *end_to_ptr = NULL;
    char exe_path[_MAX_PATH] = {'\0'};
    char *file_buffer_address = NULL;
    char *file_buffer_blacklist = NULL;
    char *file_buffer_blacklist_temp = NULL;
    char *file_buffer_blacklist_temp_dat = NULL;
    char *file_buffer_blacklist_dat = NULL;
    char *file_buffer_body = NULL;
    char *file_buffer_ini = NULL;
    char *file_buffer_messagefile = NULL;
    char *file_buffer_namefile = NULL;
    char *file_buffer_name_from = NULL;
    char *file_buffer_relationfile = NULL;
    char *file_buffer_subject = NULL;
    char *file_buffer_subject_dat = NULL;
    int file_handle = 0;
    int file_handle_address = 0;
    int file_handle_blacklist = 0;
    int file_handle_blacklist_dat = 0;
    int file_handle_blacklist_temp = 0;
    int file_handle_blacklist_temp_dat = 0;
    int file_handle_body = 0;
    int file_handle_ini = 0;
    int file_handle_messagefile = 0;
    int file_handle_namefile = 0;
    int file_handle_name_from = 0;
    int file_handle_relationfile = 0;
    int file_handle_subject = 0;
    int file_size_address = 0;
    int file_size_blacklist = 0;
    int file_size_blacklist_dat = 0;
    int file_size_blacklist_temp = 0;
    int file_size_blacklist_temp_dat = 0;
    int file_size_ini = 0;
    int file_size_messagefile = 0;
    int file_size_namefile = 0;
    int file_size_name_from = 0;
    int file_size_relationfile = 0;
    int file_size_subject = 0;
    int file_size_subject_dat = 0;
    char *filter_buffer = NULL;
    char filter4_ini[_MAX_PATH] = {'\0'};
    char *filter4_ini_ptr = NULL;
    FILESTATUS3  fsts3ConfigInfo = {{0}};       /* Buffer for file information */
    char *from = NULL;
    char *from_ptr = NULL;
    int fromaddress = 0;
    char *from_mailadress = NULL;
    char *from_name = NULL;
    char from_name_path[_MAX_PATH] = {'\0'};
    char *from_name_ptr = NULL;
    char frommail_buffer[256] = {'\0'};
    int fromname = 0;
    char fromname_buffer[256] = {'\0'};
    int g_no_loop = 0;
    char *HELO_adress = NULL;
    int ini_value = 100;
    char *IP_adress = NULL;
    int ip_link = 0;
    ULONG ip_name_file = 0;
    char *key_ptr = NULL;
    int leave = 0;
    int len = 0;
    int len_key = 0;
    int len_subject = 0;
    int len_from = 0;
    int len_from_mailadress = 0;
    int len_from_name = 0;
    int len_subject_line = 0;
    int len_total = 0;
    int line = 0;
    char *log_path_ptr = NULL;
    int time_diff  = 0;
    int log_after_relation = 0;
    int log_all_recipients = 0;
    int loop = 0;
    int mailbombing = 0;
    int mark_counter = 0;
    int max_number_of_recipients = 0;
    char messagefile[512] = {'\0'};
    char messagefile_del[512] = {'\0'};
    int message_id = 0;
    char *message_id_ptr = NULL;
    struct stat messagefile_size_buffer;
    int MIME_version = 0;
    char *mime_version_ptr = NULL;
    int min_body = 0;
    int min_subject = 0;
    int minus_counter = 0;
    char namefile[512] = {'\0'};
    char namefile_del[512] = {'\0'};
    struct stat namefile_size_buffer;
    int new_line = 0;
    long new_size_messagefile = 0;
    int no_loop = 0;
    char *no_loop_ptr = 0;
    int number_of_recipients = 0;
    int number_of_final_recipients = 0;
    int num_file_address = 0;
    int num_file_blacklist = 0;
    int num_file_blacklist_dat = 0;
    int num_file_blacklist_temp = 0;
    int num_file_blacklist_temp_dat = 0;
    int num_file_body = 0;
    int num_file_ini = 0;
    int num_file_messagefile = 0;
    int num_file_namefile = 0;
    int num_file_name_from = 0;
    int num_file_relationfile = 0;
    int num_file_subject = 0;
    int num_file_subject_dat =0;
    char *out_buffer = NULL;
    char *possible_new_line = NULL;
    int priority = 0;
    APIRET rc = NO_ERROR;      /* Return code */
    char *recipient_ptr = NULL;
    int recieved = 0;
    char *received_ptr = NULL;
    char *relation_file = NULL;
    char relation_file_path[_MAX_PATH] = {'\0'};
    int reply_to = 0;
    char *reply_to_ptr = NULL;
    int remove_list_lines = 0;
    int rest = 0;
    int rest_address = 0;
    int rest_bodyfile = 0;
    int rest_messagefile = 0;
    int rest_name_from = 0;
    int rest_num_file = 0;
    int rest_subjectfile = 0;
    char *result = NULL;
    char *result1 = NULL;
    int returnpath = 0;
    char *return_path_ptr = NULL;
    int returnpath_size = 0;
    int returnpath_value = 0;
    int return_value = 0;
    char schalter[2] = {'\0'};
    char *sender = NULL;
    int sender_found = 0;
    int size_out_buffer = 0;
    int stop = 0;
    char string1[_MAX_PATH] = {'\0'};
    char str_counter = 0;
    char *subject = NULL;
    char subject_path[_MAX_PATH] = {'\0'};
    char *subject_line = NULL;
    int subject_I = 0;
    int substitud = 0;
    int value = 0;
    char weasel_filter4_ini[_MAX_PATH] = {'\0'};
    int whitelist = 0;
    int wkey = 0;
    char *temp_ptr = NULL;
    char temp_buffer[260] = {'\0'};
    int temp_len = 0;
    char *temp_write_buffer = NULL;
    int to = 0;
    char *to_ptr = NULL;
    int to_adress = 0;
    int total_score = 0;
    int trigger_value = 99;
    time_t ltime = 0.0;
    double start_time;
    double end_time;
    double timedif;
    ULONG ulBufSize = sizeof(FILESTATUS3);  /* Size of above buffer */
    char Weasel_path[_MAX_PATH] = {'\0'};
    char *write_buffer_namefile = NULL;



    start_time = (double)clock();               /* get initial time in seconds      */
    start_time = start_time/CLOCKS_PER_SEC;
    _fullpath(Weasel_path, ".", _MAX_PATH);
    strcpy(string1, Weasel_path);
    _fullpath(exe_path, argv[0], _MAX_PATH);
    _splitpath(exe_path, drive, dir, fname, ext);
    memset(exe_path, '\0', _MAX_PATH);
    strcat(exe_path, drive);
    strcat(exe_path, dir);
    memcpy(filter4_ini, exe_path, _MAX_PATH);
    strcat(filter4_ini, "filter4.ini");

    #ifdef _F_DEBUG
        stream1 = fopen("debug.log","a");
        fprintf(stream1, "\n\n . path %s\n Weaselpath %s\n argv[0] %s\n argv[1] %s\n Argv[2] %s\n", exe_path, Weasel_path, argv[0], argv[1],argv[2]);
        fclose(stream1);
    #endif


    if(argc == 2)
        {
        strcat(Weasel_path, "\\");
        strcpy(weasel_filter4_ini, Weasel_path);
        strcat(weasel_filter4_ini, "filter4.ini");
        strcpy(messagefile, "copy ");
        strcat(messagefile, argv[1]);
        strcat(messagefile, " messagefile1");
        strcpy(messagefile_del, "del ");
        strcat(messagefile_del, "messagefile1");
        }
    namefile_size_buffer;
    stat(argv[1], &namefile_size_buffer);
    stat(argv[2], &messagefile_size_buffer);


    if(argc == 3)
        {
        strcat(Weasel_path, "\\");
        strcpy(weasel_filter4_ini, Weasel_path);
        strcat(weasel_filter4_ini, "filter4.ini");
        strcat(string1, "\\");
        strcat(string1, argv[2]);
        strcpy(namefile, "copy ");
        strcpy(messagefile, "copy ");
        strcat(namefile, argv[1]);
        strcat(namefile, " namefile1");
        strcat(messagefile, argv[2]);
        strcat(messagefile, " messagefile1");
        strcpy(namefile_del, "del ");
        strcpy(messagefile_del, "del ");
        strcat(namefile_del, "namefile1");
        strcat(messagefile_del, "messagefile1");
        argv2 = argv[2];
        }

    #ifdef _F_DEBUG
        stream1 = fopen("debug.log","a");
        fprintf(stream1, "Filter4.ini=  %s (have to bee null) line 337\n", filter4_ini_ptr);
        fclose(stream1);
    #endif


    time(&ltime);

    /* Convert it to the structure tm */
    newtime = localtime(&ltime);
    if(access(filter4_ini, 00) == 0)
        {
        filter4_ini_ptr = filter4_ini;
    #ifdef _F_DEBUG
        stream1 = fopen("debug.log","a");
        fprintf(stream1, "access filter4.ini =%s 346\n", filter4_ini_ptr);
        fclose(stream1);
    #endif
        }

    else if(access(weasel_filter4_ini, 00) == 0)
        {
        filter4_ini_ptr = weasel_filter4_ini;
    #ifdef _F_DEBUG
        stream1 = fopen("debug.log","a");
        fprintf(stream1, "access %s filter4.in in line 356\n", filter4_ini_ptr);
        fclose(stream1);
    #endif

        }
    else
        {
        filter4_ini_ptr = filter4_ini;
    #ifdef _F_DEBUG
        stream1 = fopen("debug.log","a");
        fprintf(stream1, "final %s filter4.ini linr 357\n", filter4_ini_ptr);
        fclose(stream1);
    #endif

        }

    file_handle_ini = open(filter4_ini_ptr, O_CREAT | O_TEXT | O_RDWR, S_IREAD | S_IWRITE);             /*Datei zum Lesen îffnen*/
    if(file_handle_ini == -1)                                              /*Fehler */
        {
        if(errortracking)
            {
            stream = fopen("filter_4_error.log","a");
            fprintf(stream, "%s Open %s missmatched %i, \n", asctime(newtime),filter4_ini_ptr,  errno);
            fclose(stream);
            close(file_handle_ini);                                            /* Datei Schliessen*/
            }
        }
    #ifdef _F_DEBUG
        stream1 = fopen("debug.log","a");
        fprintf(stream1, "open %s filehandle = %i linr 390\n", filter4_ini_ptr, file_handle_ini);
        fclose(stream1);
    #endif


    file_size_ini = filelength(file_handle_ini);

    #ifdef _F_DEBUG
        stream1 = fopen("debug.log","a");
        fprintf(stream1, "file size filter4.ini = %i bytes line 400\n", file_size_ini);
        fclose(stream1);
    #endif

    if(file_size_ini == -1L)                                /* Grîsse Åbergeben*/
        {
        if(errortracking)
            {
            stream = fopen("filter_4_error.log","a");
            fprintf(stream,"%s file_size filter_4ini %i, \nUnable to determine length of inifile.\n", asctime(newtime), errno);
            fclose(stream);
            close(file_handle_ini);                                            /* Datei Schliessen*/
            }
        }


    buffer_size_ini = file_size_ini + 1024;
    file_buffer_ini = (char*) calloc(buffer_size_ini, sizeof(char));            /*speicher reservieren*/
    if(file_buffer_ini == NULL)                                      /*bei einem Fehler*/
        {
        if(errortracking)
            {
            stream = fopen("filter_4_error.log","a");
            fprintf(stream, "%s file_buffer_ini %i, \n", asctime(newtime), errno);
            fclose(stream);
            close(file_handle_ini);                                            /* Datei Schliessen*/
            }
        }

    if(file_size_ini == 0)
        {
        sprintf(file_buffer_ini,"whitelist=1\n"
                                "blacklist=1\n"
                                "blacklist_temp=0\n"
                                "returnpath=0\n"
                                "recieved=0\n"
                                "From_name=0\n"
                                "From_address=1\n"
                                "to_name=0\n"
                                "reply_to=0\n"
                                "to_adress=0\n"
                                "priority=0\n"
                                "content_type=1\n"
                                "content_transfer_encoding=1\n"
                                "message_id=0\n"
                                "mime_version=0\n"
                                "Subject=1\n"
                                "Body_Scan=1\n"
                                "Body_Scan_Size=4\n"
                                "Body_Scan_Multipart=1\n"
                                "Mailbombing=0\n"
                                "Bombing_Amount=5\n"
                                "Bombing_time=15\n"
                                "Bann_Time=24\n"
                                "Trigger_Value=99\n"
                                "Empty_Subject=20\n"
                                "Minimum_subject_size=7\n"
                                "Empty_body=50\n"
                                "Minimum_body_size=50\n"
                                "Substitud=0\n"
                                "Stop=1\n"
                                "Log=1\n"
                                "IP_link=100\n"
                                "Log_directory=\n"
                                "Log_errors=1\n"
                                "copy_message=0\n"
                                "debug=0\n"
                                "refuse_self_adressing=0\n"
                                "address_file=\n"
                                "body_file=\n"
                                "subject_file=\n"
                                "fromname_file=\n"
                                "log_runtime=0\n"
                                "log_all_recipients=0\n"
                                "log_after_relations=0\n"
                                "max_number_of_recipients=0\n"
                                "check_relations=0\n"
                                "relation_file=\n"
                                "remove_list_lines=0\n"
                                );
        write(file_handle_ini, file_buffer_ini, 732);
        memset(file_buffer_ini, '\0', 1024);
        }


    close(file_handle_ini);
    file_handle_ini = open(filter4_ini_ptr, O_BINARY | O_RDWR, S_IREAD | S_IWRITE);
        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s line 444 \n", filter4_ini_ptr);
            fclose(stream1);
        #endif
    file_size_ini = filelength(file_handle_ini);
    num_file_ini = read(file_handle_ini, file_buffer_ini, file_size_ini);       /* Datei einlesen  num = die eingelesenen Zeilen*/
    close(file_handle_ini);
    memset(&file_buffer_ini[num_file_ini], '\0', 1);

    counter = 0;
    rest_num_file = num_file_ini;
    while(counter < num_file_ini)
        {
        new_line = 0;
        result = memchr(&file_buffer_ini[counter], '\r', rest_num_file);

        if(!result)
            {
            result = memchr(&file_buffer_ini[counter], '\n', rest_num_file);
            }
        if(result)
            {
            memset(result, '\0',1);
            counter = result - file_buffer_ini;
            rest_num_file = num_file_ini - counter -1;
            }
        else
            {
            break;
            }
        }

    whitelist = check_ini(num_file_ini, file_buffer_ini, "whitelist");
    blacklist = check_ini(num_file_ini, file_buffer_ini, "blacklist");
    blacklist_temp = check_ini(num_file_ini, file_buffer_ini, "blacklist_temp");
    returnpath = check_ini(num_file_ini, file_buffer_ini, "returnpath");
    recieved = check_ini(num_file_ini, file_buffer_ini, "recieved");
    fromname = check_ini(num_file_ini, file_buffer_ini, "From_name");
    fromaddress = check_ini(num_file_ini, file_buffer_ini, "From_address");
    to = check_ini(num_file_ini, file_buffer_ini, "to_name");
    reply_to = check_ini(num_file_ini, file_buffer_ini, "reply_to");
    to_adress = check_ini(num_file_ini, file_buffer_ini, "to_adress");
    priority = check_ini(num_file_ini, file_buffer_ini, "priority");
    content_type = check_ini(num_file_ini, file_buffer_ini, "content_type");
    content_transfer_encoding = check_ini(num_file_ini, file_buffer_ini, "content_transfer_encoding");
    message_id = check_ini(num_file_ini, file_buffer_ini, "message_id");
    MIME_version = check_ini(num_file_ini, file_buffer_ini, "mime_version");
    subject_I = check_ini(num_file_ini, file_buffer_ini, "Subject");
    body_scan = check_ini(num_file_ini, file_buffer_ini, "Body_Scan");
    body_scan_size = check_ini(num_file_ini, file_buffer_ini, "Body_Scan_Size");
    body_scan_multipart = check_ini(num_file_ini, file_buffer_ini, "Body_Scan_Multipart");
    mailbombing = check_ini(num_file_ini, file_buffer_ini, "Mailbombing");
    bombing_amount = check_ini(num_file_ini, file_buffer_ini, "Bombing_Amount");
    bombing_time = check_ini(num_file_ini, file_buffer_ini, "Bombing_time");
    bann_time = check_ini(num_file_ini, file_buffer_ini, "Bann_Time");
    trigger_value = check_ini(num_file_ini, file_buffer_ini, "Trigger_Value");
    empty_subject = check_ini(num_file_ini, file_buffer_ini, "Empty_Subject");
    min_subject = check_ini(num_file_ini, file_buffer_ini, "Minimum_subject_size");
    empty_body = check_ini(num_file_ini, file_buffer_ini, "Empty_body");
    min_body = check_ini(num_file_ini, file_buffer_ini, "Minimum_body_size");
    substitud = check_ini(num_file_ini, file_buffer_ini, "Substitud");
    stop = check_ini(num_file_ini, file_buffer_ini, "Stop");
    logging = check_ini(num_file_ini, file_buffer_ini, "Log");
    ip_link = check_ini(num_file_ini, file_buffer_ini, "IP_link");
    log_path_ptr = check_ini_P(num_file_ini, file_buffer_ini, "Log_directory");
    errortracking = check_ini(num_file_ini, file_buffer_ini, "Log_errors");
    copy_file = check_ini(num_file_ini, file_buffer_ini, "copy_message");
    debug_crash = check_ini(num_file_ini, file_buffer_ini, "debug");
    g_no_loop = check_ini(num_file_ini, file_buffer_ini, "refuse_self_adressing");
    adress = check_ini_P(num_file_ini, file_buffer_ini, "address_file");
    body_file = check_ini_P(num_file_ini, file_buffer_ini, "body_file");
    subject = check_ini_P(num_file_ini, file_buffer_ini, "subject_file");
    from_name = check_ini_P(num_file_ini, file_buffer_ini, "fromname_file");
    time_diff = check_ini(num_file_ini, file_buffer_ini, "log_runtime");
    log_all_recipients = check_ini(num_file_ini, file_buffer_ini, "log_all_recipients");
    log_after_relation = check_ini(num_file_ini, file_buffer_ini, "log_after_relations");
    max_number_of_recipients = check_ini(num_file_ini, file_buffer_ini, "max_number_of_recipients");
    check_relation = check_ini(num_file_ini, file_buffer_ini, "check_relations");
    relation_file = check_ini_P(num_file_ini, file_buffer_ini, "realtion_file=");
    remove_list_lines = check_ini(num_file_ini, file_buffer_ini, "remove_list_lines");

    free(file_buffer_ini);
        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "adressfile: %s fromaddress: %i line 513\n", adress, fromaddress);
            fclose(stream1);
        #endif



    if(debug_crash)
        {
        if(access("namefile1" ,00) == -1)
            {
            if(argc == 3)
                {
                system(namefile);
                }
            system(messagefile);
            }
        else
            {
            debug_crash = 0;
            }

        }

    if(copy_file)
        {
        if(argc == 3)
            {
            system(namefile);
            }
        system(messagefile);
        }


    if(log_path_ptr == NULL)
        {
        _fullpath(log_path, ".", _MAX_PATH);
        strcat(log_path, "\\");
        strcat(log_path_error, log_path);
        strcat(log_path_error, "filter_4_error.log");
        strcat(log_path, "filter_4.log");
        }
    else
        {
        rc = DosQueryPathInfo(log_path_ptr,   /* Path and name of file           */
                              FIL_STANDARD,  /* Request standard (Level 1) info */
                              &fsts3ConfigInfo, /* Buffer for file information  */
                              ulBufSize);    /* Size of buffer                  */
        if(rc == NO_ERROR)
            {
            strcpy(log_path, log_path_ptr);
            strcat(log_path, "\\");
            strcat(log_path_error, log_path);
            strcat(log_path_error, "filter_4_error.log");
            strcat(log_path, "filter_4.log");
            }
        else
            {
            stream = fopen("filter_4_error.log","a");
            fprintf(stream, "%s Log Path %s does not exist! \n", asctime(newtime), log_path_ptr);
            fclose(stream);
            _fullpath(log_path, ".", _MAX_PATH);
            strcat(log_path, "\\");
            strcat(log_path_error, log_path);
            strcat(log_path_error, "filter_4_error.log");
            strcat(log_path, "filter_4.log");
            }
        }


/************************ end ini file, open namefile ***************************/

    if(argc == 3)
        {
        file_handle_namefile = open(argv[1], O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
        if(file_handle_namefile == -1)                                              /*Fehler */
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream, "%s %i, %s File does not exist! \n", asctime(newtime), errno, argv[1]);
                fclose(stream);
                close(file_handle_namefile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }
        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s \n", argv[1]);
            fclose(stream1);
        #endif

        file_size_namefile = filelength(file_handle_namefile);
        if(file_size_namefile == 0)                                /* Grîsse Åbergeben*/
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream, "The file ini is empty.\n");
                fclose(stream);
                close(file_handle_namefile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }

        if(file_size_namefile == -1L)                                /* Grîsse Åbergeben*/
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream,"%s file_size_namefile %i, \n", asctime(newtime), errno);
                printf("Unable to determine length of inifile.\n");
                fclose(stream);
                close(file_handle_namefile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }

        buffer_size_namefile = file_size_namefile;
        file_buffer_namefile = (char*) calloc(++buffer_size_namefile, sizeof(char));            /*speicher reservieren*/
        if(file_buffer_namefile == NULL)                                      /*bei einem Fehler*/
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream, "%s file_buffer_name_file %i, \n", asctime(newtime), errno);
                fclose(stream);
                close(file_handle_namefile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }

        if(check_relation)
            {
            write_buffer_namefile = (char*) calloc(++buffer_size_namefile, sizeof(char));            /*speicher reservieren*/
            temp_write_buffer = (char*) calloc(++buffer_size_namefile, sizeof(char));            /*speicher reservieren*/
            }
        num_file_namefile = read(file_handle_namefile, file_buffer_namefile, file_size_namefile);       /* Datei einlesen  num = die eingelesenen Zeilen*/
        close(file_handle_namefile);
        memset(&file_buffer_namefile[num_file_namefile], '\0', 1);

        ip_name_file = ip_2_Ulong(file_buffer_namefile, domain);

        domain = strchr(file_buffer_namefile, ' ');
        domain++;
        begin_line = file_buffer_namefile;
        end = memchr(begin_line, '\r', num_file_namefile);
        if(end && memcmp(end + 1, "\n", 1) != 0)
            {
            new_line = 1;
            }
        if(!end)
            {
            end = memchr(begin_line, '\n', num_file_namefile);
            if(end)
                {
                new_line = 1;
                }
            }
        if(end)
            {
            memset(end, '\0', 1);
            IP_adress = begin_line;
            if(logging)
                {
                stream = fopen(log_path,"a");
                fprintf(stream,"%sSending IP-Adress: %s\n", asctime(newtime), begin_line);
                }

            if(check_relation)
                {
                len_total += sprintf(&write_buffer_namefile[len_total], "%s\n", begin_line);
                }
            if(new_line == 1)
                {
                begin_line = end + 1;
                }
            else
                {
                begin_line = end + 2;
                }
            rest = num_file_namefile - (end - file_buffer_namefile);
            }

        new_line = 0;
        end = memchr(begin_line, '\r', rest);
        if(end && memcmp(end + 1, "\n", 1) != 0)
            {
            new_line = 1;
            }

        if(!end)
            {
            end = memchr(begin_line, '\n', rest);
            if(end)
                {
                new_line = 1;
                }
            }
        if(end)
            {
            memset(end, '\0', 1);
            HELO_adress = begin_line;
            if(logging)
                {
                fprintf(stream,"HELO Adress: %s\n", begin_line);
                }
            if(check_relation)
                {
                len_total += sprintf(&write_buffer_namefile[len_total], "%s\n", begin_line);
                }
            if(new_line)
                {
                begin_line = end + 1;
                }
            else
                {
                begin_line = end + 2;
                }
            rest = num_file_namefile - (end - file_buffer_namefile);
            }

        new_line = 0;
        end = memchr(begin_line, '\r', rest);
        if(end && memcmp(end + 1, "\n", 1) != 0)
            {
            new_line = 1;
            }

        if(!end)
            {
            end = memchr(begin_line, '\n', rest);
            if(end)
                {
                new_line = 1;
                }
            }
        if(end)
            {
            memset(end - 1, '\0', 1);
            from_mailadress = begin_line + 1;
            if(logging)
                {
                fprintf(stream,"Mail From Address: %s>\n", begin_line);
                }
            if(check_relation)
                {
                len_total += sprintf(&write_buffer_namefile[len_total], "%s>\n\n", begin_line);
                }
            if(new_line)
                {
                begin_line = end + 2;
                }
            else
                {
                begin_line = end + 4;
                }
            rest = num_file_namefile - (end - file_buffer_namefile);
            }

        recipient_ptr = begin_line;
        while(rest > 7 && rest < num_file_namefile + 1)
            {
            new_line = 0;
            to_ptr = begin_line;
            end = memchr(begin_line, '\r', rest);
            if(end && memcmp(end + 1, "\n", 1) != 0)
                {
                new_line = 1;
                }

            if(!end)
                {
                end = memchr(begin_line, '\n', rest);
                new_line = 1;
                }
            if(end)
                {
                memset(end, '\0', 1);
                }
            if(logging && log_all_recipients)
                {
                fprintf(stream,"Mail to: %s\n", begin_line);
                }

            len = f_strlen(to_ptr);
            if(! loop && len)
                {
                if(memicmp(from_mailadress, to_ptr, len) == 0)
                    {
                    if(number_of_recipients == 0)
                        {
                        loop = 2;
                        }
                    else
                        {
                        loop = 1;
                        }
                    }
                }
            rest = num_file_namefile - (end - file_buffer_namefile);
            if(new_line)
                {
                begin_line = end + 1;
                }
            else
                {
                begin_line = end + 2;
                }
            if((memcmp(begin_line, "\n", 1) == 0) || (memcmp(begin_line, "\r", 1) == 0))
                {
                if(new_line)
                    {
                    begin_line++;
                    rest--;
                    }
                else
                    {
                    begin_line += 2;
                    rest -= 2;
                    }
                }
            number_of_recipients++;
            if(number_of_recipients > max_number_of_recipients && max_number_of_recipients > 0)
                {
                free(filter_buffer);
                return(3);
                }
            }
        fclose(stream);
        new_line = 0;
        end = NULL;
        }


/****************************************************************************/

    if(check_relation)
        {
        if(relation_file == NULL || access(relation_file, 04) != 0)
            {
            strcat(relation_file_path, exe_path);
            strcat(relation_file_path, "\\");
            strcat(relation_file_path, "relation");
            relation_file = relation_file_path;
            }
        if(access(relation_file, 04) == 0)
            {
            file_handle_relationfile = open(relation_file, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
            if(file_handle_relationfile == -1)                                              /*Fehler */
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s open_relation %i \n", asctime(newtime), errno);
                    fclose(stream);
                    }
                }
            }
        else
            {
            memset(relation_file, '\0', _MAX_PATH);
            strcat(relation_file, Weasel_path);
            strcat(relation_file, "\\");
            strcat(relation_file, "relation");
            if(access(relation_file, 04) == 0)
                {
                file_handle_relationfile = open(relation_file, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
                if(file_handle_relationfile == -1)                                              /*Fehler */
                    {
                    if(errortracking)
                        {
                        stream = fopen(log_path_error,"a");
                        fprintf(stream,"%s file_handle_relation %i, \n", asctime(newtime), errno);
                        fclose(stream);
                        }
                    }
                }
            }

        file_size_relationfile = filelength(file_handle_relationfile);
        if(file_size_relationfile == 0)                                /* Grîsse Åbergeben*/
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream, "The file ini is empty.\n");
                fclose(stream);
                close(file_handle_relationfile);                                            /* Datei Schliessen*/

                }
            }

        if(file_size_relationfile == -1L)                                /* Grîsse Åbergeben*/
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream,"%s file_size_relationfile %i, \n", asctime(newtime), errno);
                printf("Unable to determine length of relationfile.\n");
                fclose(stream);
                close(file_handle_relationfile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }

        buffer_size_relationfile = file_size_relationfile;
        file_buffer_relationfile = (char*) calloc(++buffer_size_relationfile, sizeof(char));            /*speicher reservieren*/
        if(file_buffer_relationfile == NULL)                                      /*bei einem Fehler*/
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream, "%s file_buffer_relation_file %i, \n", asctime(newtime), errno);
                fclose(stream);
                close(file_handle_relationfile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }

        num_file_relationfile = read(file_handle_relationfile, file_buffer_relationfile, file_size_relationfile);       /* Datei einlesen  num = die eingelesenen Zeilen*/
        close(file_handle_relationfile);
        memset(&file_buffer_relationfile[num_file_relationfile], '\0', 1);


/**************************/

        number_of_recipients = 0;
        len_from_mailadress = f_strlen(from_mailadress);
        begin_line = recipient_ptr;
        rest = num_file_relationfile;
        while(rest > 6 && rest < num_file_relationfile + 1)
            {
            new_line = 0;
            sender_found = 0;
            to_ptr = begin_line;
            end = memchr(begin_line, '\r', rest);
            if(end && memcmp(end + 1, "\n", 1) != 0)
                {
                new_line = 1;
                }

            if(!end)
                {
                end = memchr(begin_line, '\n', rest);
                new_line = 1;
                }
            if(end)
                {
                memset(end, '\0', 1);
                }

            len = f_strlen(to_ptr);

            if(check_relation && len)
                {
                sender_found = checkrelation(file_buffer_relationfile, num_file_relationfile, from_mailadress, len_from_mailadress, to_ptr);
                if(sender_found == 1 )
                    {
                    len_total += sprintf(&write_buffer_namefile[len_total], "%s\n", begin_line);
                    number_of_final_recipients++;
                    }

                if(sender_found == -1)
                    {
                    len = end - begin_line;
                    }

                if(sender_found == 0)
                    {
                    temp_len += sprintf(&temp_write_buffer[temp_len], "%s\n", begin_line);
                    number_of_recipients++;
                    }
                }

            if((logging && log_after_relation) || (logging && ! number_of_recipients ))
                {
                stream = fopen(log_path,"a");
                if(time_diff)
                    {
                    end_time = (double)clock();               /* get initial time in seconds      */
                    end_time = end_time/CLOCKS_PER_SEC;
                    timedif = end_time - start_time;
                    fprintf(stream, "Runtime: %f Seconds\n", timedif);
                    }
                if(sender_found == -1)
                    {
                    fprintf(stream, "Mail to: %s not sent. Rejectet by user relation.\n", begin_line);
                    }
                else if(sender_found == 1)
                    {
                    fprintf(stream, "Mail to: %s sent without filtering. Bypassed by user relation.\n", begin_line);
                    }

                else
                    {
                    fprintf(stream,"Mail to: %s filterd\n", begin_line);
                    }
                fclose(stream);
                }

            if(! loop && len)
                {
                if(memicmp(from_mailadress, to_ptr, len) == 0)
                    {
                    if(number_of_recipients == 0)
                        {
                        loop = 2;
                        }
                    else
                        {
                        loop = 1;
                        }
                    }
                }
            rest = num_file_namefile - (end - file_buffer_namefile);
            if(new_line)
                {
                begin_line = end + 1;
                }
            else
                {
                begin_line = end + 2;
                }

            if(number_of_recipients > max_number_of_recipients && max_number_of_recipients > 0)
                {
                free(filter_buffer);
                stream = fopen(log_path,"a");
                if(time_diff)
                    {
                    end_time = (double)clock();               /* get initial time in seconds      */
                    end_time = end_time/CLOCKS_PER_SEC;
                    timedif = end_time - start_time;
                    fprintf(stream, "Runtime: %f Seconds\n", timedif);
                    }
                fprintf(stream, "Message rejected only too many recipients\n\n");
                fclose(stream);
                return(3);
                }

            }

        if(number_of_final_recipients && number_of_recipients == 0)
            {
            stream = fopen(log_path,"a");
            fprintf(stream, "\n");
            fclose(stream);
            stream = fopen(argv[1],  "w");
            fprintf(stream, "%s", write_buffer_namefile);
            fclose(stream);
            if(time_diff)
                {
                end_time = (double)clock();               /* get initial time in seconds      */
                end_time = end_time/CLOCKS_PER_SEC;
                timedif = end_time - start_time;
                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                }
            return(1);
            }

        new_line = 0;
        end = NULL;
        if(number_of_recipients < 1 && number_of_final_recipients < 1)
            {
            free(filter_buffer);
            stream = fopen(log_path,"a");
            if(time_diff)
                {
                end_time = (double)clock();               /* get initial time in seconds      */
                end_time = end_time/CLOCKS_PER_SEC;
                timedif = end_time - start_time;
                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                }
            fprintf(stream, "No recipients left\n\n");
            fclose(stream);
            return(3);
            }

        }




/************************ open Messagefile ***************************/

    if(argc == 3)
        {
        file_handle_messagefile = open(argv[2], O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/

        if(file_handle_messagefile == -1)                                              /*Fehler */
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream, "%s open_message_file %i \n", asctime(newtime), errno);
                fclose(stream);
                close(file_handle_messagefile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }
        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s line 721 \n", argv[2]);
            fclose(stream1);
        #endif

        }
    else
        {
        file_handle_messagefile = open(argv[1], O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
        if(file_handle_messagefile == -1)                                              /*Fehler */
            {
            if(errortracking)
                {
                stream = fopen(log_path_error,"a");
                fprintf(stream, "%s open_message_file %i \n", asctime(newtime), errno);
                fclose(stream);
                close(file_handle_messagefile);                                            /* Datei Schliessen*/
                exit(0);
                }
            }
        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s line 742\n", argv[1]);
            fclose(stream1);
        #endif

        }


    file_size_messagefile = filelength(file_handle_messagefile);
    if(file_size_messagefile == 0)                                /* Grîsse Åbergeben*/
        {
        if(errortracking)
            {
            stream = fopen(log_path_error,"a");
            fprintf(stream, "The file message is empty.\n");
            fclose(stream);
            close(file_handle_messagefile);                                            /* Datei Schliessen*/
            exit(0);
            }
        }

    if(file_size_messagefile == -1L)                                /* Grîsse Åbergeben*/
        {
        if(errortracking)
            {
            stream = fopen(log_path_error,"a");
            fprintf(stream,"%s file_size_message_file %i \n", asctime(newtime), errno);
            printf("Unable to determine length of messagefile.\n");
            fclose(stream);
            close(file_handle_messagefile);                                            /* Datei Schliessen*/
            exit(0);
            }
        }

    buffer_size_messagefile = file_size_messagefile;
    file_buffer_messagefile = (char*) calloc(buffer_size_messagefile + 8, sizeof(char));            /*speicher reservieren*/
    if(file_buffer_messagefile == NULL)                                      /*bei einem Fehler*/
        {
        if(errortracking)
            {
            stream = fopen(log_path_error,"a");
            fprintf(stream, "%s file_buffer_message_file %i \n", asctime(newtime), errno);
            fclose(stream);
            close(file_handle_messagefile);                                            /* Datei Schliessen*/
            exit(0);
            }
        }

    num_file_messagefile = read(file_handle_messagefile, file_buffer_messagefile, file_size_messagefile);       /* Datei einlesen  num = die eingelesenen Zeilen*/

    close(file_handle_messagefile);
    memset(&file_buffer_messagefile[num_file_messagefile], '\0', 1);
    if(body_scan_size)
        {
        if(num_file_messagefile > body_scan_size * 1024 + 1)
            {
            num_file_messagefile = body_scan_size * 1024;
            memset(&file_buffer_messagefile[num_file_messagefile + 1], '\0', 1);
            }
        }

    begin_line = file_buffer_messagefile;
    rest_messagefile = num_file_messagefile;
    counter = 0;
    leave = 0;

            #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "Nach lesen von Messagefile Grîsse = num_file_messagefile %i line 809\n", num_file_messagefile);
            fclose(stream1);
            #endif

    while(!leave)
        {
        new_line = 0;
        return_value = 0;
        if(end == NULL)
            {
            if(begin_line == NULL)
                {
                rest_messagefile = num_file_messagefile;
                }
            else
                {
                rest_messagefile = &file_buffer_messagefile[num_file_messagefile] - begin_line;
                }
            }
        else
            {
            rest_messagefile = num_file_messagefile - (end - file_buffer_messagefile);
            }
        end = memchr(begin_line, '\r', rest_messagefile);
        if(end && memcmp(end + 1, "\n", 1) != 0)
            {
            new_line = 1;
            }

        if(!end)
            {
            end = memchr(begin_line, '\n', rest_messagefile);
            if(end)
                {
                new_line = 1;
                }
            }
        if(end)
            {
            memset(end, '\0', 1);
            }
        else
            {
            rest_messagefile = 0;
            leave = 1;
            break;
            }
        len = f_strlen(begin_line);

        if(new_line)
            {
            if(memcmp(end + 1, "\r", 1) == 0 || memcmp(end + 1, "\n", 1) != 0)
                {
                body = end + 2;
                if(memcmp(body + 1, "\n", 1) == 0)
                    {
                    body++;
                    }
                leave = 1;
                }
            }
        else
            {
            if(memcmp(end + 2, "\r", 1) == 0)
                {
                body = end + 4;
                leave = 1;
                }
            }

        if(!subject_line && subject_I)
            {
            if(memicmp(begin_line, "Subject:", 8) == 0)
                {
                subject_line = begin_line + 9;
                return_value = test_of_empty_subject(subject_line, empty_subject, min_subject);
                if(argc == 3)
                    {
                    if(logging && return_value)
                        {
                        stream = fopen(log_path,"a");
                        fprintf(stream, "Score : %i, Empty Subject\n", return_value);
                        fclose(stream);
                        }
                    }

                value += return_value;
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }
        if(!cc_ptr)
            {
            if(memicmp(begin_line, "CC:", 3) == 0)
                {
                cc_ptr = begin_line + 3;
                len = f_strlen(cc_ptr);
                len--;
                cc_ptr = strchr(cc_ptr, '<');
                if(cc_ptr)
                    {
                    rest_messagefile = num_file_messagefile - (end - file_buffer_messagefile);
                    end = memchr(begin_line, '\r', rest_messagefile);
                    if(end && memcmp(end + 1, "\n", 1) != 0)
                        {
                        new_line = 1;
                        }

                    if(!end)
                        {
                        end = memchr(begin_line, '\n', rest_messagefile);
                        if(end)
                            {
                            new_line = 1;
                            }
                        }

                    memset(cc_ptr, '\0', 1);
                    cc_ptr++;
                    end_cc_ptr = strchr(cc_ptr, '>');
                    memset(end_cc_ptr, '\0', 1);
                    }
                else
                    {
                    cc_ptr = begin_line + 4;
                    }
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!bcc_ptr)
            {
            if(memicmp(begin_line, "BCC:", 4) == 0)
                {
                bcc_ptr = begin_line + 4;
                len = f_strlen(bcc_ptr);
                len--;
                bcc_ptr = strchr(bcc_ptr, '<');
                if(bcc_ptr)
                    {
                    memset(bcc_ptr, '\0', 1);
                    bcc_ptr++;
                    end_bcc_ptr = strchr(bcc_ptr, '>');
                    memset(end_bcc_ptr, '\0', 1);
                    }
                else
                    {
                    bcc_ptr = begin_line + 4;
                    }
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!from_mailadress || !from_name_ptr)
            {
            if(memicmp(begin_line, "From:", 5) == 0)
                {
                if(! from_mailadress)
                    {
                    from_mailadress = get_from_mailadress(begin_line);
                    }
                if (! from_mailadress)
                    {
                    free(file_buffer_messagefile);
                    return(3);
                    }
                from_name_ptr = &begin_line[5];
                continue;
                }
            }

        if(!to_ptr)
            {
            if(memicmp(begin_line, "To:", 3) == 0)
                {
                to_ptr = begin_line + 4;
                len = f_strlen(to_ptr);
                len--;
                to_ptr = strchr(to_ptr, '<');
                if(to_ptr)
                    {
                    memset(to_ptr, '\0', 1);
                    to_ptr++;
                    end_to_ptr = strchr(to_ptr, '>');
                    memset(end_to_ptr, '\0', 1);
                    }
                else
                    {
                    to_ptr = begin_line + 4;
                    }
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!date_ptr)
            {
            if(memicmp(begin_line, "Date:", 5) == 0)
                {
                date_ptr = begin_line + 6;
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }


        if(!return_path_ptr && returnpath)
            {
            if(memicmp(begin_line, "Return-Path:", 12) == 0)
                {
                return_path_ptr = begin_line + 13;
                len = f_strlen(return_path_ptr);
                len--;
                memset(&return_path_ptr[len], '\0', 1);
                if(returnpath)
                    {
                    result = memchr(return_path_ptr, '<', len);
                    if (result)
                        {
                        result++;
                        }

                    if(returnpath)
                        {
                        return_value = 1;
                        if(return_value == - 1)
                            {
                            free(file_buffer_messagefile);
                            return(3);
                            }
                        }
                    }

                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }

            }
        if(!received_ptr && recieved)
            {
            if(memicmp(begin_line, "Received:", 9) == 0)
                {
                received_ptr = begin_line + 10;
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!reply_to_ptr && reply_to)
            {
            if(memicmp(begin_line, "Reply-To:", 9) == 0)
                {
                reply_to_ptr = begin_line + 10;
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!content_type_ptr && content_type)
            {
            if(memicmp(begin_line, "Content-Type:", 13) == 0)
                {
                content_type_ptr = begin_line + 14;
                if(memicmp(content_type_ptr, "multipart", 9) == 0)
                    {
                    boundary = 1;
                    }
                else if(memicmp(content_type_ptr, "base64", 6) == 0)
                    {
                    base64 = 1;
                    }
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!base64 && content_transfer_encoding)
            {
            if(memicmp(begin_line, "Content-Transfer-Encoding:", 26) == 0)
                {
                base64_ptr = stristr(begin_line + 27, len - 27, "base64", 6);
                if(base64_ptr)
                    {
                    base64 = 1;
                    }
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }


        if(!message_id_ptr && message_id)
            {
            if(memicmp(begin_line, "Message-ID:", 11) == 0)
                {
                message_id_ptr = begin_line + 12;
                len = f_strlen(message_id_ptr);
                len--;
                memset(&message_id_ptr[len], '\0', 1);

           /*     if(message_id)
                    {
                    check_message_id(message_id); /*function

                    } */

                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!mime_version_ptr && MIME_version)
            {
            if(memicmp(begin_line, "MIME-Version:", 13) == 0)
                {
                mime_version_ptr = begin_line + 14;
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(!temp_ptr && empty_body)
            {
            temp_ptr = stristr(begin_line, len, " boundary=", 10);
            if(temp_ptr)
                {
                boundary_ptr = temp_ptr + 11;
                if(new_line)
                    {
                    begin_line = end + 1;
                    }
                else
                    {
                    begin_line = end + 2;
                    }
                continue;
                }
            }

        if(remove_list_lines)
            {
            if(memicmp(begin_line, "List-", 5) == 0)
                {
                do
                    {
                    if(! begin_cut_out)
                        {
                        begin_cut_out = begin_line - file_buffer_messagefile;
                        }

                    new_line = 0;
                    return_value = 0;
                    if(end == NULL)
                        {
                        if(begin_line == NULL)
                            {
                            rest_messagefile = num_file_messagefile;
                            }
                        else
                            {
                            rest_messagefile = &file_buffer_messagefile[num_file_messagefile] - begin_line;
                            }
                        }
                    else
                        {
                        rest_messagefile = num_file_messagefile - (end - file_buffer_messagefile);
                        }
                    end = memchr(begin_line, '\r', rest_messagefile);
                    if(end && memcmp(end + 1, "\n", 1) != 0)
                        {
                        new_line = 1;
                        begin_line = end + 1;
                        }

                    if(!end)
                        {
                        end = memchr(begin_line, '\n', rest_messagefile);
                        if(end)
                            {

                            begin_line = end + 1;
                            }
                        }
                    else
                        {
                        begin_line = end + 2;
                        }

                    if(new_line)
                        {
                        if(memcmp(end + 1, "\r", 1) == 0 || memcmp(end + 1, "\n", 1) != 0)
                            {
                            body = end + 2;
                            if(memcmp(body, "\n", 1) == 0)
                                {
                                body++;
                                }
                            leave = 1;
                            break;
                            }
                        }
                    else
                        {
                        if(memcmp(end + 2, "\r", 1) == 0)
                            {
                            body = end + 4;
                            leave = 1;
                            break;
                            }
                        }

                    } while(memicmp(begin_line, "List-", 5) == 0);
                }
            }


        if(new_line)
            {
            begin_line = end + 1;
            }
        else
            {
            begin_line = end + 2;
            }
        }
    len = f_strlen(to_ptr);
    if(memicmp(from_mailadress, to_ptr, len) == 0)
        {
        loop = 1;
        }

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "rest_message_file = %i line 1021\n", rest_messagefile);
            fclose(stream1);
        #endif

    if(argc == 2 && logging)
        {
        stream = fopen(log_path, "a");
        fprintf(stream, "Date and Time %s\n", date_ptr);
        fprintf(stream,"Mail From Address: <%s>\n", from_mailadress);
        fprintf(stream,"Mail to: %s\n", to_ptr);
        fclose(stream);
        }

    if(!body)
        {
        if(logging)
            {
            stream = fopen(log_path,"a");
            if(time_diff)
                {
                end_time = (double)clock();               /* get initial time in seconds      */
                end_time = end_time/CLOCKS_PER_SEC;
                timedif = end_time - start_time;
                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                }
            fprintf(stream, "Score : No  body \nMessage rejected\n\n");
            fclose(stream);
            }
        return(3);
        }

    if((&file_buffer_messagefile[num_file_messagefile] - body) < 5)
        {
        if(debug_crash)
            {
            if(argc == 3)
                {
                system(namefile_del);
                }
            system(messagefile_del);
            }
        if(logging)
            {
            stream = fopen(log_path,"a");
            if(time_diff)
                {
                end_time = (double)clock();               /* get initial time in seconds      */
                end_time = end_time/CLOCKS_PER_SEC;
                timedif = end_time - start_time;
                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                }
            fprintf(stream, "Score : No  body \nMessage rejected\n\n");
            fclose(stream);
            }
        if(! check_relation)
            {
            free(filter_buffer);
            free(file_buffer_messagefile);
            return(3);
            }
        else
            {
            stream = fopen(argv[1],  "w");
            fprintf(stream, "%s", write_buffer_namefile);
            fclose(stream);
            if(begin_cut_out)
                {
                cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                }
            free(file_buffer_messagefile);
            return(1);
            }
        }

    free(file_buffer_namefile);


/*************************From file ******************/

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "fromadress = %i line 1046\n", fromaddress);
            fclose(stream1);
        #endif

    if(fromaddress)
        {
        if(adress == NULL || access(adress, 00) != 0)
            {
            strcat(adress_path, exe_path);
            strcat(adress_path, "adress");
            adress = adress_path;
            }

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "adress nach adress = NULL %s  line 1050\n", adress);
            fclose(stream1);
        #endif

        if(access(adress, 00) == 0)
            {
            file_handle_address = open(adress, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
            if(file_handle_address == -1)                                              /*Fehler */
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s file_handle_adress %i, \n", asctime(newtime), errno);
                    fclose(stream);
                    }
                }

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "adress nach adress im Adress_path %s line 1060\n", adress);
            fclose(stream1);
        #endif

            }
        else
            {
            memset(adress_path, '\0', _MAX_PATH);
            strcat(adress_path, Weasel_path);
            strcat(adress_path, "adress");
            adress = adress_path;
            if(access(adress, 00) == 0)
                {
                file_handle_address = open(adress, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
                if(file_handle_address == -1)                                              /*Fehler */
                    {
                    if(errortracking)
                        {
                        stream = fopen(log_path_error,"a");
                        fprintf(stream,"%s file_handle_adress %i, \n", asctime(newtime), errno);
                        fclose(stream);
                        }
                    }
                }

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "adress nach adress = Weasel_path %s line 1070\n", adress);
            fclose(stream1);
        #endif

            }

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s \n", adress);
            fclose(stream1);
        #endif

        if(file_handle_address > 0)
            {
            file_size_address = filelength(file_handle_address);
            if(file_size_address == 0)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"Adressfile is empty.\n");
                    fclose(stream);
                    }
                }

            if(file_size_address == -1L)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%i, .\n");
                    printf("Unable to determine length of address.\n");
                    fclose(stream);
                    close(file_handle_address);
                    }
                }

            buffer_size_address = file_size_address;
            file_buffer_address = (char*) calloc(++buffer_size_address, sizeof(char));            /*speicher reservieren*/
            if(file_buffer_address == NULL)                                      /*bei einem Fehler*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s file_buffer_adress %i \n", asctime(newtime), errno);
                    fclose(stream);
                    close(file_handle_address);                                           /* Datei Schliessen*/
                    }
                }

            num_file_address = read(file_handle_address, file_buffer_address, file_size_address);       /* Datei einlesen  num = die eingelesenen Zeilen*/
            close(file_handle_address);
            memset(&file_buffer_address[num_file_address], '\0', 1);
            rest_address = num_file_address;
            counter = 0;
            leave = 0;
            while(counter < num_file_address && value < trigger_value && !leave)
                {
                new_line = 0;
                line++;
                minus_counter = 0;
                no_loop = 0;
                no_loop_ptr = NULL;
                key_ptr = NULL;
                wkey = 0;
                leave = 0;
                result1 = memchr(&file_buffer_address[counter], '\r', rest_address);
                if(result1 && memcmp(result1 + 1, "\n", 1) != 0)
                    {
                    new_line = 1;
                    }
                if(!result1)
                    {
                    result1 = memchr(&file_buffer_address[counter], '\n', rest_address);
                    new_line = 1;
                    }

                if(result1)
                    {
                    memset(result1, '\0', 1);
                    len = result1 - &file_buffer_address[counter];
                    }
                else
                    {
                    len = num_file_address - counter;
                    }

                if(! g_no_loop && loop)
                    {
                    no_loop_ptr = strstr(&file_buffer_address[counter], "/NL");
                    if(no_loop_ptr)
                        {
                        no_loop = 1;
                        }
                    }

                if(no_loop && loop || g_no_loop && loop)
                    {
                    key_ptr = strstr(&file_buffer_address[counter], "/KEY");

                    if(key_ptr == NULL)
                        {
                        key_ptr = strstr(&file_buffer_address[counter], "/WKEY");
                        if(key_ptr)
                            {
                            wkey = 1;
                            }
                        }
                    }
                else
                    {
                    key_ptr = strstr(&file_buffer_address[counter], "/WKEY");
                    if(key_ptr)
                        {
                        wkey = 1;
                        }
                    }

                if(no_loop_ptr || key_ptr)
                    {
                    if(no_loop_ptr && no_loop_ptr < key_ptr)
                        {
                        minus_counter = no_loop_ptr - file_buffer_address;
                        while(no_loop_ptr > &file_buffer_address[counter])
                            {
                            memcpy(&character, &file_buffer_address[minus_counter], 1);
                            if(isalnum(character))
                                {
                                minus_counter++;
                                memset(&file_buffer_address[minus_counter], '\0', 1);
                                break;
                                }
                             else
                                {
                                minus_counter--;
                                }
                            }

                        }
                    else
                        {
                        minus_counter = key_ptr - file_buffer_address;
                        while(key_ptr > &file_buffer_address[counter])
                            {
                            memcpy(&character, &file_buffer_address[minus_counter], 1);
                            if(isalnum(character))
                                {
                                minus_counter++;
                                memset(&file_buffer_address[minus_counter], '\0', 1);
                                break;
                                }
                             else
                                {
                                minus_counter--;
                                }
                            }
                        }
                    }


                len_from_mailadress = f_strlen(from_mailadress);

                for(str_counter = 0; str_counter < len; str_counter++)
                    {
                    memcpy(&character, &file_buffer_address[counter + str_counter], 1);
                    character = tolower(character);
                    memcpy(&file_buffer_address[counter + str_counter], &character, 1);
                    }

                return_value = test_mail_addres(from_mailadress, len_from_mailadress, &file_buffer_address[counter], len, ini_value);

                if(logging && return_value)
                    {
                    stream = fopen(log_path,"a");
                    fprintf(stream, "AScore : %i, %s\n", return_value, from_mailadress);
                    fclose(stream);
                    }
                if(return_value == -1)
                    {
                    error_stream = fopen(log_path_error,"a");
                    fprintf(stream, "Error in file adress, in line %i, mailadres \" %s\"\n", line, &file_buffer_address[counter]);
                    fclose(error_stream);
                    }
                else if(return_value)
                    {
                    value += return_value;
                    if(loop && (no_loop || g_no_loop) && !key_ptr)
                        {
                        if(logging)
                            {
                            stream = fopen(log_path,"a");
                            if(time_diff)
                                {
                                end_time = (double)clock();               /* get initial time in seconds      */
                                end_time = end_time/CLOCKS_PER_SEC;
                                timedif = end_time - start_time;
                                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                                }
                            fprintf(stream, "No Loop allowed for %s\nMessage rejected\n\n", from_mailadress);
                            fclose(stream);
                            }
                        if(! check_relation)
                            {
                            free(file_buffer_messagefile);
                            return(3);
                            }
                        else
                            {
                            stream = fopen(argv[1],  "w");
                            fprintf(stream, "%s", write_buffer_namefile);
                            fclose(stream);
                            if(begin_cut_out)
                                {
                                cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                                }
                            free(file_buffer_messagefile);
                            return(1);
                            }

                        }
                    leave = 1;
                    }


                counter = result1 - file_buffer_address;
                if(new_line == 1)
                    {
                    counter++;
                    }
                else
                    {
                    counter+=2;
                    }
                rest_address = num_file_address - counter;
                if(counter <= 0)
                    {
                    leave = 1;
                    }
                }
            leave = 0;

            if(value > trigger_value)
                {
                if(logging)
                    {
                    stream = fopen(log_path,"a");
                    if(time_diff)
                        {
                        end_time = (double)clock();               /* get initial time in seconds      */
                        end_time = end_time/CLOCKS_PER_SEC;
                        timedif = end_time - start_time;
                        fprintf(stream, "Runtime: %f Seconds\n", timedif);
                        }
                    fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                    total_score = 1;
                    fclose(stream);
                    }
                if(mailbombing)
                    {
                    track_mail(ip_name_file, domain, from_mailadress, bann_time, bombing_amount, bombing_time);
                    }
                if(debug_crash)
                    {
                    if(argc == 3)
                        {
                        system(namefile_del);
                        }
                    system(messagefile_del);
                    }
                if(! check_relation)
                    {
                    free(file_buffer_messagefile);
                    return(3);
                    }
                else
                    {
                    stream = fopen(argv[1],  "w");
                    fprintf(stream, "%s", write_buffer_namefile);
                    fclose(stream);

                    if(begin_cut_out)
                        {
                        cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                        }
                    free(file_buffer_messagefile);
                    return(1);
                    }
                }

            close(file_handle_address);

            }
        }


 /**********************************************/

    MIME_version = check_ini(num_file_ini, file_buffer_ini, "mime-version");

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "nach Suche von Key %s line 1406\n", key_ptr);
            fclose(stream1);
        #endif

    if(key_ptr)
        {
        len_key = f_strlen(key_ptr);
        key_ptr = memchr(key_ptr, 34, len_key);
        key_ptr++;
        len_key = f_strlen(key_ptr);
        end = memchr(key_ptr, 34, len_key);
        memset(end, '\0', 1);
        end = NULL;
        len_key--;
        rest_messagefile = &file_buffer_messagefile[num_file_messagefile] - body;
        if(rest_messagefile > 512)
            {
            temp_len = 515;
            }
        else
            {
            temp_len = rest_messagefile;
            }

         result = search_for_key(body, temp_len, key_ptr, len_key);


        if(! result && no_loop)
            {
            if(logging)
                {
                stream = fopen(log_path,"a");
                if(time_diff)
                    {
                    end_time = (double)clock();               /* get initial time in seconds      */
                    end_time = end_time/CLOCKS_PER_SEC;
                    timedif = end_time - start_time;
                    fprintf(stream, "Runtime: %f Seconds\n", timedif);
                    }
                fprintf(stream, "Score : No self mailing allowed for <%s>\nMessage rejected\n\n", from_mailadress);
                fclose(stream);
                }
            if(!check_relation)
                {
                free(file_buffer_messagefile);
                return(3);
                }
            else
                {
                stream = fopen(argv[1],  "w");
                fprintf(stream, "%s", write_buffer_namefile);
                fclose(stream);
                if(begin_cut_out)
                    {
                    cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                    }
                free(file_buffer_messagefile);
                return(1);
                }

            }
        if(result && wkey)
            {
            if(logging)
                {
                stream = fopen(log_path,"a");
                if(time_diff)
                    {
                    end_time = (double)clock();               /* get initial time in seconds      */
                    end_time = end_time/CLOCKS_PER_SEC;
                    timedif = end_time - start_time;
                    fprintf(stream, "Runtime: %f Seconds\n", timedif);
                    }
                if(!check_relation)
                    {
                    fprintf(stream, "White Key dedected: No filter activated for mail from <%s>\nMessage keept.\n\n", from_mailadress);
                    }
                else if(number_of_final_recipients)
                    {
                    fprintf(stream, "White Key dedected: No filter activated for mail from <%s>\nMessage keept. sent to %i recipients\n\n", from_mailadress, number_of_final_recipients);
                    }
                else
                    {
                    fprintf(stream, "White Key dedected: No filter activated for mail from <%s>\nMessage keept. But not sent by relation\n\n", from_mailadress);
                    }
                fclose(stream);
                }
            if(!check_relation)
                {
                free(file_buffer_messagefile);
                return(3);
                }
            else
                {
                stream = fopen(argv[1],  "w");
                fprintf(stream, "%s%s", write_buffer_namefile, temp_write_buffer);
                fclose(stream);
                len = f_strlen(temp_write_buffer);
                if(number_of_final_recipients || len)
                    {

                    if(begin_cut_out)
                        {
                        cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                        }
                    free(file_buffer_messagefile);
                    return(1);
                    }
                else
                    {
                    free(file_buffer_messagefile);
                    return(3);
                    }
                }
            }
        }

    free(file_buffer_address);

    new_line = 0;

/***************** From_name_test *********************/

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "vor FromName line 1472\n");
            fclose(stream1);
        #endif

    if(fromname)
        {
        if(from_name == NULL || access(from_name, 00) != 0)
            {
            strcat(from_name_path, exe_path);
            strcat(from_name_path, "from_name");
            from_name = from_name_path;
            }

        if(access(from_name, 00) == 0)
            {
            file_handle_name_from = open(from_name, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
            if(file_handle_name_from == -1)                                              /*Fehler */
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s file_handle_name_from %i, \n", asctime(newtime), errno);
                    fclose(stream);
                    }
                }
            }
        else
            {
            memset(from_name, '\0', _MAX_PATH);
            strcat(from_name, Weasel_path);
            strcat(from_name, "from_name");
            if(access(from_name, 00) == 0)
                {
                file_handle_name_from = open(from_name, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
                if(file_handle_address == -1)                                              /*Fehler */
                    {
                    if(errortracking)
                        {
                        stream = fopen(log_path_error,"a");
                        fprintf(stream,"%s file_handle_from_name %i, \n", asctime(newtime), errno);
                        fclose(stream);
                        }
                    }
                }

            }

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s line 1521\n", from_name);
            fclose(stream1);
        #endif
        if(file_handle_name_from > 0)
            {
            file_size_name_from = filelength(file_handle_name_from);
            if(file_size_name_from == 0)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"name_fromfile is empty.\n");
                    fclose(stream);
                    }
                }

            if(file_size_name_from == -1L)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%i, .\n");
                    printf("Unable to determine length of name_from.\n");
                    fclose(stream);
                    close(file_handle_name_from);
                    }
                }

            buffer_size_name_from = file_size_name_from;
            file_buffer_name_from = (char*) calloc(++buffer_size_name_from, sizeof(char));            /*speicher reservieren*/
            if(file_buffer_name_from == NULL)                                      /*bei einem Fehler*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s file_buffer_adress %i \n", asctime(newtime), errno);
                    fclose(stream);
                    close(file_handle_name_from);                                           /* Datei Schliessen*/
                    }
                }

            len_from = f_strlen(from_name_ptr);
            from_ptr = (char*)calloc(++len_from, sizeof(char));

            memcpy(from_ptr, from_name_ptr, len_from);
            result = memchr(from_ptr, '<', len_from);
            if (result)
                {
                memset(result, '\0', 1);
                len_from = f_strlen(from_ptr);
                }

            rest = len_from;
            while(mark_counter < 2 )
                {
                result = memchr(&from_ptr[mark_counter], 34, rest);
                mark_counter++;
                if(result)
                    {
                    if(mark_counter < 2)
                        {
                        memcpy(&character, from_ptr, 1);
                        if(isalnum(character) == 0)
                            {
                            from_ptr++;
                            rest = &from_ptr[rest] - result;
                            rest--;
                            }
                        else
                            {
                            rest = &begin_line[len] - result;
                            mark_counter = 2;
                            }
                        }
                    }
                else
                    {
                    break;
                    }
                }
            if(mark_counter == 2 && result)
                {
                memset(result,'\0', 1);
                }
            else
                {
                result = memchr(&from_ptr[mark_counter], '>', rest);
                if(result)
                    {
                    memset(result, '\0', 1);
                    }
                else
                    {
                    end = &from_ptr[len];
                    while(from_ptr < end + 1)
                        {
                        memcpy(&character, from_ptr, 1);
                        if(isalnum(character) == 0)
                            {
                            from_ptr++;
                            rest = end - from_ptr;
                            rest--;
                            }
                        else
                            {
                            break;
                            }
                        }
                    }
                }

            num_file_name_from = read(file_handle_name_from, file_buffer_name_from, file_size_name_from);       /* Datei einlesen  num = die eingelesenen Zeilen*/
            close(file_handle_name_from);
            memset(&file_buffer_name_from[num_file_name_from], '\0', 1);
            rest_name_from = num_file_name_from;
            counter = 0;
            leave = 0;
            while(counter < num_file_name_from && value < trigger_value && !leave)
                {
                new_line = 0;
                line++;
                minus_counter = 0;
                no_loop = 0;
                no_loop_ptr = NULL;
                key_ptr = NULL;
                wkey = 0;
                leave = 0;
                result1 = memchr(&file_buffer_name_from[counter], '\r', rest_name_from);
                if(result1 && memcmp(result1 + 1, "\n", 1) != 0)
                    {
                    new_line = 1;
                    }
                if(!result1)
                    {
                    result1 = memchr(&file_buffer_name_from[counter], '\n', rest_name_from);
                    new_line = 1;
                    }
                if(result1)
                    {
                    memset(result1, '\0', 1);
                    len = result1 - &file_buffer_name_from[counter];
                    }
                else
                    {
                    len = num_file_name_from - counter;
                    }


                len_from = f_strlen(from_ptr);

                return_value = test_subject(from_ptr, len_from, &file_buffer_name_from[counter], len, ini_value);
                if(return_value == -1)
                    {
                    error_stream = fopen(log_path_error,"a");
                    fprintf(error_stream, "Error in file name on line %i \"%s\"\n", line, &file_buffer_name_from[counter]);
                    fclose(error_stream);
                    }
                else
                    {
                    value += return_value;
                    }

                if(logging && return_value)
                    {
                    stream = fopen(log_path,"a");
                    memcpy(&schalter, log_PTR, 1);
                    fprintf(stream, "NScore : %i %s %s\n", return_value, schalter, &log_PTR[1]);
                    fclose(stream);
                    }

                counter = result1 - file_buffer_name_from;
                if(new_line == 1)
                    {
                    counter++;
                    }
                else
                    {
                    counter+=2;
                    }
                rest_name_from = num_file_name_from - counter;
                if(counter <= 0)
                    {
                    leave = 1;
                    }
                }
            leave = 0;

            if(value > trigger_value)
                {
                if(logging)
                    {
                    stream = fopen(log_path,"a");
                    if(time_diff)
                        {
                        end_time = (double)clock();               /* get initial time in seconds      */
                        end_time = end_time/CLOCKS_PER_SEC;
                        timedif = end_time - start_time;
                        fprintf(stream, "Runtime: %f Seconds\n", timedif);
                        }
                    fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                    total_score = 1;
                    fclose(stream);
                    }
                if(mailbombing)
                    {
                    track_mail(ip_name_file, domain, from_mailadress, bann_time, bombing_amount, bombing_time);
                    }
                if(debug_crash)
                    {
                    if(argc == 3)
                        {
                        system(namefile_del);
                        }
                    system(messagefile_del);
                    }
                if(!check_relation)
                    {
                    free(file_buffer_messagefile);
                    return(3);
                    }
                else
                    {
                    stream = fopen(argv[1],  "w");
                    fprintf(stream, "%s", write_buffer_namefile);
                    fclose(stream);
                    if(begin_cut_out)
                        {
                        cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                        }
                    free(file_buffer_messagefile);
                    return(1);
                    }
                }

            close(file_handle_name_from);
            free(file_buffer_name_from);
            }
        }

        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s line 2574\n", from_name);
            fclose(stream1);
        #endif
/************ test if subject has been chanched ****************/


    if(subject_I)
        {
        if(subject == NULL ||access(subject, 00) != 0)
            {
            strcat(subject_path, exe_path);
            strcat(subject_path, "subject");
            subject = subject_path;
            }
        if(access(subject, 00) == 0)
            {

            file_handle_subject = open(subject, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
            if(file_handle_subject == -1)                                              /*Fehler */
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s open_file_handle_subject %i \n", asctime(newtime), errno);
                    fclose(stream);
                    }
                }
            }
        else
            {
            memset(subject, '\0', _MAX_PATH);
            strcat(subject, Weasel_path);
            strcat(subject, "subject");
            if(access(subject, 00) == 0)
                {
                file_handle_subject = open(subject, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
                if(file_handle_subject == -1)                                              /*Fehler */
                    {
                    if(errortracking)
                        {
                        stream = fopen(log_path_error,"a");
                        fprintf(stream,"%s file_handle_subject %i, \n", asctime(newtime), errno);
                        fclose(stream);
                        }
                    }
                }

            }
        if(file_handle_subject > 1)
            {
        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s \n", subject);
            fclose(stream1);
        #endif

            file_size_subject = filelength(file_handle_subject);
            if(file_size_subject == 0)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"The file subject is empty.\n");
                    fclose(stream);
                    }
                }

            if(file_size_subject == -1L)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%i, .\n");
                    printf("Unable to determine length of subject.\n");
                    fclose(stream);
                    close(file_handle_subject);
                    }
                }

            buffer_size_subject = file_size_subject;
            file_buffer_subject = (char*) calloc(++buffer_size_subject, sizeof(char));            /*speicher reservieren*/
            if(file_buffer_subject == NULL)                                      /*bei einem Fehler*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s file_buffer_subject %i \n", asctime(newtime), errno);
                    fclose(stream);
                    close(file_handle_subject);                                           /* Datei Schliessen*/
                    }
                }

            num_file_subject = read(file_handle_subject, file_buffer_subject, file_size_subject);       /* Datei einlesen  num = die eingelesenen Zeilen*/
            close(file_handle_subject);
            memset(&file_buffer_subject[num_file_subject], '\0', 1);
            rest_subjectfile = num_file_subject;
            counter = 0;
            len_subject_line = f_strlen(subject_line);
            line = 0;
            while(counter < num_file_subject && value < trigger_value)
                {
                line++;
                new_line = 0;
                result1 = memchr(&file_buffer_subject[counter], '\r', rest_subjectfile);
                if(result1 && memcmp(result1 + 1, "\n", 1) != 0)
                    {
                    new_line = 1;
                    }
                if(!result1)
                    {
                    result1 = memchr(&file_buffer_subject[counter], '\n', rest_subjectfile);
                    }
                if(result1)
                    {
                    memset(result1, '\0', 1);
                    len = result1 - &file_buffer_subject[counter];
                    if(new_line)
                        {
                        possible_new_line = result + 1;
                        }
                    else
                        {
                        possible_new_line = result1 + 2;
                        }
                    }
                else
                    {
                    len = &file_buffer_subject[num_file_subject] - possible_new_line;
                    counter = num_file_subject;
                    }

                return_value =  test_subject(subject_line, len_subject_line, &file_buffer_subject[counter], len, ini_value);
                if(return_value == -1)
                    {
                    error_stream = fopen(log_path_error,"a");
                    fprintf(error_stream, "Error in file subject on line %i \"%s\"\n", line, &file_buffer_subject[counter]);
                    fclose(error_stream);
                    }
                else
                    {
                    value += return_value;
                    }
                if(logging && return_value > 0)
                    {
                    stream = fopen(log_path,"a");
                    memcpy(&schalter, log_PTR, 1);
                    fprintf(stream, "SScore : %i %s %s\n", return_value, schalter, &log_PTR[1]);
                    fclose(stream);
                    }


                counter = result1 - file_buffer_subject;
                if(new_line)
                    {
                    counter++;
                    }
                else
                    {
                    counter+=2;
                    }
                rest_subjectfile = num_file_subject - counter;
                if(counter <= 0)
                    {
                    break;
                    }
                }

            if(value > trigger_value)
                {
                if(logging && stop)
                    {
                    stream = fopen(log_path,"a");
                    if(time_diff)
                        {
                        end_time = (double)clock();               /* get initial time in seconds      */
                        end_time = end_time/CLOCKS_PER_SEC;
                        timedif = end_time - start_time;
                        fprintf(stream, "Runtime: %f Seconds\n", timedif);
                        }
                    fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                    total_score = 1;
                    fclose(stream);
                    }

                if(mailbombing)
                    {
                    track_mail(ip_name_file, domain, from_mailadress, bann_time, bombing_amount, bombing_time);
                    }
                if(stop)
                    {
                    if(debug_crash)
                        {
                        if(argc == 3)
                            {
                            system(namefile_del);
                            }
                        system(messagefile_del);
                        }
                    if(!check_relation)
                        {
                        free(file_buffer_messagefile);
                        return(3);
                        }
                    else
                        {
                        stream = fopen(argv[1],  "w");
                        fprintf(stream, "%s", write_buffer_namefile);
                        fclose(stream);
                        if(begin_cut_out)
                            {
                            cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                            }
                        free(file_buffer_messagefile);
                        return(1);
                        }
                    }
                }

            free(file_buffer_subject);
            }
        }


/************ test if Body is activated ****************/


    if(body_scan)
        {
        if(body_file == NULL || access(body_file, 04) != 0)
            {
            strcat(body_file_path, exe_path);
            strcat(body_file_path, "body");
            body_file = body_file_path;
            }
        if(access(body_file, 04) == 0)
            {
            file_handle_body = open(body_file, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
            if(file_handle_body == -1)                                              /*Fehler */
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s open_body %i \n", asctime(newtime), errno);
                    fclose(stream);
                    }
                }
            }
        else
            {
            memset(body_file, '\0', _MAX_PATH);
            strcat(body_file, Weasel_path);
            strcat(body_file, "body");
            if(access(body_file, 04) == 0)
                {
                file_handle_body = open(body_file, O_RDONLY | O_BINARY);             /*Datei zum Lesen îffnen*/
                if(file_handle_body == -1)                                              /*Fehler */
                    {
                    if(errortracking)
                        {
                        stream = fopen(log_path_error,"a");
                        fprintf(stream,"%s file_handle_body %i, \n", asctime(newtime), errno);
                        fclose(stream);
                        }
                    }
                }

            }
        if(file_handle_body > 1 )
            {
        #ifdef _F_DEBUG
            stream1 = fopen("debug.log","a");
            fprintf(stream1, "open %s \n", body_file);
            fclose(stream1);
        #endif

            file_size_body = filelength(file_handle_body);
            if(file_size_body == 0)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"The file Blacklist is empty.\n");
                    fclose(stream);
                    }
                }

            if(file_size_body == -1L)                                /* Grîsse Åbergeben*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%i, .\n");
                    printf("Unable to determine length of sample.dat.\n");
                    fclose(stream);
                    close(file_handle_body);
                    }
                }

            buffer_size_body = file_size_body + 2;
            file_buffer_body = (char*) calloc(buffer_size_body, sizeof(char));            /*speicher reservieren*/
            if(file_buffer_body == NULL)                                      /*bei einem Fehler*/
                {
                if(errortracking)
                    {
                    stream = fopen(log_path_error,"a");
                    fprintf(stream,"%s file_buffer_body %i \n", asctime(newtime), errno);
                    fclose(stream);
                    close(file_handle_body);                                           /* Datei Schliessen*/
                    }
                }

            num_file_body = read(file_handle_body, file_buffer_body, file_size_body);       /* Datei einlesen  num = die eingelesenen Zeilen*/
            close(file_handle_body);
            memset(&file_buffer_body[num_file_body], '\0', 1);
            rest_bodyfile = num_file_body;
            rest_messagefile = &file_buffer_messagefile[num_file_messagefile] - body;
            if(rest_messagefile < 4)
                {
                if(logging)
                    {
                    stream = fopen(log_path,"a");
                    if(time_diff)
                        {
                        end_time = (double)clock();               /* get initial time in seconds      */
                        end_time = end_time/CLOCKS_PER_SEC;
                        timedif = end_time - start_time;
                        fprintf(stream, "Runtime: %f Seconds\n", timedif);
                        }
                    fprintf(stream, "There is nothing in the Body!\nMessage rejected\n\n", value);
                    fclose(stream);
                    }
                if(debug_crash)
                    {
                    if(argc == 3)
                        {
                        system(namefile_del);
                        }
                    system(messagefile_del);
                    }
                if(!check_relation)
                    {
                    free(file_buffer_messagefile);
                    return(3);
                    }
                else
                    {
                    stream = fopen(argv[1],  "w");
                    fprintf(stream, "%s", write_buffer_namefile);
                    fclose(stream);
                    if(begin_cut_out)
                        {
                        cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                        }
                    free(file_buffer_messagefile);
                    return(1);
                    }
                }


            if(empty_body)
                {
                body_size = &file_buffer_messagefile[num_file_messagefile] - body;
                body_size--;
                if(body_size < min_body)
                    {
                    value += empty_body;
                    if(logging && empty_body)
                        {
                        stream = fopen(log_path,"a");
                        fprintf(stream, "BScore : Empty body %i\n", empty_body);
                        fclose(stream);
                        }
                     }

                else if(boundary_ptr)
                    {
                    return_value = check_empty_body(body, body_size, boundary_ptr, empty_body);
                    value += return_value;
                    if(logging && return_value)
                        {
                        stream = fopen(log_path,"a");
                        fprintf(stream, "BScore : %i Empty Body\n", return_value);
                        fclose(stream);
                        }
                    }

                }


        if((base64 && content_transfer_encoding) || (base64 && content_type))
            {

            out_buffer = (char*) calloc(body_size, sizeof(char));
            end_decode = decode(body, body_size, out_buffer, &size_out_buffer );
            memcpy(body, out_buffer, size_out_buffer);
            memset(&body[size_out_buffer], 32, 1);
            if(end_decode)
                {
                rest = body_size - end_decode;
                memmove(&body[size_out_buffer + 1], &body[end_decode], rest);
                }
            rest_messagefile = size_out_buffer + rest;
            memset(&body[rest_messagefile], '\0', 1);
            free(out_buffer);
            }

            counter = 0;
            possible_new_line = file_buffer_body;
            if(stop)
                {
                if(ip_link)
                    {
                    return_value = test_ip_link(body, rest_messagefile);
                    if(return_value)
                        {
                        value += ip_link;
                        if(logging && value > trigger_value && !total_score)
                            {
                            stream = fopen(log_path,"a");
                            if(time_diff)
                                {
                                end_time = (double)clock();               /* get initial time in seconds      */
                                end_time = end_time/CLOCKS_PER_SEC;
                                timedif = end_time - start_time;
                                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                                }
                            fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                            total_score = 1;
                            fclose(stream);
                            }
                        }
                    }

                stream = fopen(log_path,"a");

                if(value > trigger_value && !total_score)
                    {
                    if(time_diff)
                        {
                        end_time = (double)clock();               /* get initial time in seconds      */
                        end_time = end_time/CLOCKS_PER_SEC;
                        timedif = end_time - start_time;
                        fprintf(stream, "Runtime: %f Seconds\n", timedif);
                        }
                    fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                    total_score = 1;
                    stop = 0;
                    }

                line = 0;
                while(counter < num_file_body && value < trigger_value && stop)
                    {
                    line++;
                    new_line = 0;
                    return_value = 0;
                    result1 = memchr(&file_buffer_body[counter], '\r', rest_bodyfile);
                    if(result1 && memcmp(result1 + 1, "\n", 1) != 0)
                        {
                        new_line = 1;
                        }

                    if(!result1)
                        {
                        result1 = memchr(&file_buffer_body[counter], '\n', rest_bodyfile);
                        new_line = 1;
                        }
                    if(result1)
                        {
                        memset(result1, '\0', 1);
                        len = result1 - &file_buffer_body[counter];
                        if(new_line)
                            {
                            possible_new_line = result1 + 1;
                            }
                        else
                            {
                            possible_new_line = result1 + 2;
                            }
                        }
                    else
                        {
                        len = &file_buffer_body[num_file_body] - possible_new_line;
                        counter = num_file_body;
                        }

                    if(rest_bodyfile > len)
                        {
                        return_value = test_subject(body, rest_messagefile, &file_buffer_body[counter], len, ini_value);
                        if(return_value == -1)
                            {
                            error_stream = fopen(log_path_error,"a");
                            fprintf(error_stream, "Error in file Body on Line %i: \"%s\"\n", line, &file_buffer_body[counter]);
                            fclose(error_stream);
                            }
                        else
                            {
                            value += return_value;
                            }
                        if(logging && return_value > 0)
                            {
                            memcpy(&schalter, log_PTR, 1);
                            fprintf(stream, "BScore : %i %s %s\n", return_value, schalter, &log_PTR[1]);
                            if(value > trigger_value && !total_score)
                                {
                                if(time_diff)
                                    {
                                    end_time = (double)clock();               /* get initial time in seconds      */
                                    end_time = end_time/CLOCKS_PER_SEC;
                                    timedif = end_time - start_time;
                                    fprintf(stream, "Runtime: %f Seconds\n", timedif);
                                    }
                                fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                                total_score = 1;
                                stop = 0;
                                }
                            }
                        }

                    if(value > trigger_value)
                        {
                        stop = 0;
                        }
                    if(result1)
                        {
                        counter = result1 - file_buffer_body;
                        if(new_line)
                            {
                            counter++;
                            }
                        else
                            {
                            counter+= 2;
                            }
                        rest_bodyfile = num_file_body - counter;
                        }
                    else
                        {
                        break;
                        }
                    if(counter <= 0)
                        {
                        break;
                        }
                    }
                fclose(stream);
                }
            else
                {
                if(ip_link)
                    {
                    return_value = test_ip_link(body, num_file_body);
                    if(return_value)
                        {
                        value += ip_link;
                        if(logging && value > trigger_value && !total_score)
                            {
                            stream = fopen(log_path,"a");
                            if(time_diff)
                                {
                                end_time = (double)clock();               /* get initial time in seconds      */
                                end_time = end_time/CLOCKS_PER_SEC;
                                timedif = end_time - start_time;
                                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                                }
                            fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                            total_score = 1;
                            fclose(stream);
                            }
                        }
                    }
                stream = fopen(log_path,"a");
                line = 0;
                while(counter < num_file_body)
                    {
                    new_line = 0;
                    result1 = memchr(&file_buffer_body[counter], '\r', rest_bodyfile);
                    if(result1 && memcmp(result1 + 1, "\n", 1) != 0)
                        {
                        new_line = 1;
                        }

                    if(!result1)
                        {
                        result1 = memchr(&file_buffer_body[counter], '\n', rest_bodyfile);
                        new_line = 1;
                        }
                    if(result1)
                        {
                        memset(result1, '\0', 1);
                        len = result1 - &file_buffer_body[counter];
                        if(new_line)
                            {
                            possible_new_line = result1 + 1;
                            }
                        else
                            {
                            possible_new_line = result1 + 2;
                            }
                        }

                    if(rest_bodyfile > len)
                        {
                        return_value = test_subject(body, rest_messagefile, &file_buffer_body[counter], len, ini_value);
                        if(return_value == -1)
                            {
                            error_stream = fopen(log_path_error,"a");
                            fprintf(error_stream, "Error in file Body on Line %i: \"%s\"\n", line, &file_buffer_body[counter]);
                            fclose(error_stream);
                            }

                        else if(return_value > 0)
                            {
                            memcpy(&schalter, log_PTR, 1);
                            fprintf(stream, "BScore : %i %s %s\n", return_value, schalter, &log_PTR[1]);
                            }
                        value += return_value;
                        }

                    if(result1)
                        {
                        counter = result1 - file_buffer_body;
                        if(new_line)
                            {
                            counter++;
                            }
                        else
                            {
                            counter+=2;
                            }
                        rest_bodyfile = num_file_body - counter;
                        }
                    else
                        {
                        break;
                        }
                    if(counter <= 0)
                        {
                        break;
                        }
                    }

                if(logging && value && !total_score)
                    {
                    if(value > trigger_value)
                        {
                        if(time_diff)
                            {
                            end_time = (double)clock();               /* get initial time in seconds      */
                            end_time = end_time/CLOCKS_PER_SEC;
                            timedif = end_time - start_time;
                            fprintf(stream, "Runtime: %f Seconds\n", timedif);
                            }
                        fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
                        }
                    else
                        {
                        if(time_diff)
                            {
                            end_time = (double)clock();               /* get initial time in seconds      */
                            end_time = end_time/CLOCKS_PER_SEC;
                            timedif = end_time - start_time;
                            fprintf(stream, "Runtime: %f Seconds\n", timedif);
                            }
                        fprintf(stream, "Total Score : %i \nMessage keept\n\n", value);
                        }
                    total_score = 1;
                    }

                fclose(stream);
                }

            if(value > trigger_value)
                {
                if(mailbombing)
                    {
                    track_mail(ip_name_file, domain, from_mailadress, bann_time, bombing_amount, bombing_time);
                    }
                fclose(stream);
                if(debug_crash )
                    {
                    if(argc == 3)
                        {
                        system(namefile_del);
                        }
                    system(messagefile_del);
                    }
                if(!check_relation)
                    {
                    free(file_buffer_messagefile);
                    return(3);
                    }
                else
                    {
                    stream = fopen(argv[1],  "w");
                    fprintf(stream, "%s", write_buffer_namefile);
                    fclose(stream);
                    if(begin_cut_out)
                        {
                        cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                        }
                    free(file_buffer_messagefile);
                    return(1);
                    }
                }

            close(file_handle_body);
            free(file_buffer_body);
            }
        }



    stream = fopen(log_path,"a");
    if(value < trigger_value)
        {
        if(!total_score)
            {
            if(time_diff)
                {
                end_time = (double)clock();               /* get initial time in seconds      */
                end_time = end_time/CLOCKS_PER_SEC;
                timedif = end_time - start_time;
                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                }

            if(!check_relation)
                {
                fprintf(stream, "Total Score : %i \nMessage keept\n\n", value);
                }
            else if(number_of_final_recipients || number_of_recipients)
                {
                fprintf(stream, "Total Score : %i \nMessage keept\n\n", value);
                }
            else
                {
                fprintf(stream, "Total Score : %i \nMessage not sent, recipient refused\n\n", value);
                }
            fclose(stream);
            }
        if(debug_crash)
            {
            if(argc == 3)
                {
                system(namefile_del);
                }
            system(messagefile_del);
            }

        if(!check_relation)
            {
            if(begin_cut_out)
                {
                cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                }
            free(file_buffer_messagefile);
            return(0);
            }
        else
            {
            stream = fopen(argv[1],  "w");
            fprintf(stream, "%s%s", write_buffer_namefile, temp_write_buffer);
            fclose(stream);
            len = f_strlen(temp_write_buffer);
            if(number_of_final_recipients || len)
                {
                if(begin_cut_out)
                    {
                    cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                    }
                free(file_buffer_messagefile);
                return(1);
                }
            else
                {
                free(file_buffer_messagefile);
                return(3);
                }
            }
        }
    else
        {
        if(!total_score)
            {
            if(time_diff)
                {
                end_time = (double)clock();               /* get initial time in seconds      */
                end_time = end_time/CLOCKS_PER_SEC;
                timedif = end_time - start_time;
                fprintf(stream, "Runtime: %f Seconds\n", timedif);
                }
            fprintf(stream, "Total Score : %i \nMessage rejected\n\n", value);
            fclose(stream);
            }
        if(debug_crash)
            {
            if(argc == 3)
                {
                system(namefile_del);
                }
            system(messagefile_del);
            }
        if(!check_relation)
            {
            if(begin_cut_out)
                {
                cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                }
            free(file_buffer_messagefile);
            return(0);
            }
        else
            {
            stream = fopen(argv[1],  "w");
            fprintf(stream, "%s", write_buffer_namefile);
            fclose(stream);
            if(number_of_final_recipients)
                {
                if(begin_cut_out)
                    {
                    cut_out_major_list_lines(begin_cut_out, argc, argv[1], argv2, log_path_error, file_buffer_messagefile, num_file_messagefile, body);
                    }
                free(file_buffer_messagefile);
                return(1);
                }
            else
                {
                free(file_buffer_messagefile);
                return(3);
                }
            }

        }

    }



ULONG ip_2_Ulong(char *ipadress, char *domain)
    {
    ULONG ip = 0;
    char buffer[128] = {'\0'};
    int counter = 0;
    int counter_end = 0;
    char *result = NULL;
    FILE *stream = NULL;
    ULONG zahl = 0;


    memcpy(buffer, ipadress, 64);

/* ip 0.x.x.x */

    while(buffer[counter] < 47 || buffer[counter] > 58)
        {
        counter++;
        }
    result = memchr(&buffer[counter], '.', 4);
    memset(result, '\0', 1);

    zahl = atol(&buffer[counter]);
    if(zahl > 256)                                              /*Fehler */
        {
        stream = fopen(log_path_error,"a");
        fprintf(stream, "Error in IP adress. Must be a number between 0 an 255 \n", errno);
        fclose(stream);
        return(0);
        }

    ip = zahl;

    counter = result - buffer;

/* ip o.o.x.x*/

    while(buffer[counter] < 47 || buffer[counter] > 58)
        {
        counter++;
        }
    result = memchr(&buffer[counter], '.', 4);
    memset(result, '\0', 1);

    zahl = atol(&buffer[counter]);
    if(zahl > 256)                                              /*Fehler */
        {
        stream = fopen(log_path_error,"a");
        fprintf(stream, "Error in IP adress. Must be a number between 0 an 255 \n", errno);
        fclose(stream);
        return(0);
        }

    ip *= 256;
    ip += zahl;

    counter = result - buffer;

/*  ip 0.0.0.x */

    while(buffer[counter] < 47 || buffer[counter] > 58)
        {
        counter++;
        }
    result = memchr(&buffer[counter], '.', 4);
    memset(result, '\0', 1);

    zahl = atol(&buffer[counter]);
    if(zahl > 256)                                              /*Fehler */
        {
        stream = fopen(log_path_error,"a");
        fprintf(stream, "Error in IP adress. Must be a number between 0 an 255 \n", errno);
        fclose(stream);
        return(0);
        }

    ip *= 256;
    ip += zahl;

    counter = result - buffer;

/* ip 0.0.0.0 */

    while(buffer[counter] < 47 || buffer[counter] > 58)
        {
        counter++;
        }

    counter_end = counter;
    while(buffer[counter_end] > 46 && buffer[counter_end] < 59)
        {
        counter_end++;
        }


    memset(&buffer[counter_end], '\0', 1);

    zahl = atol(&buffer[counter]);
    if(zahl > 256)                                              /*Fehler */
        {
        stream = fopen(log_path_error,"a");
        fprintf(stream, "Error in IP adress. Must be a number between 0 an 255 \n", errno);
        fclose(stream);
        return(0);
        }

    ip *= 256;
    ip += zahl;
                    /*    domain = &buffer[++counter_end]; */
    return(ip);
    }




int f_strlen(char *buffer)
    {
    int counter = 0;
    int leave = 1;

    if(buffer == NULL)
        {
        leave = 0;
        }

    while(leave)
        {
        leave = memcmp(&buffer[counter], "\0", 1);
        if(leave)
            {
            counter++;
            }
        }
    return(counter);
    }

int test_subject(char* subject_line, int len_line, char* subject, int len_sub, int value)
    {
    int begin = 0;
    int character = 0;
    int counter = 0;
    int compare_len = 0;
    char *double_point = NULL;
    int end = 0;
    int len = 0;
    int error = 1;
    char *result = NULL;
    char *result1 = NULL;
    char *result2 = NULL;
    char *result3 = NULL;
    char *result4 = NULL;
    char *result5 = NULL;
    char *result6 = NULL;
    int rest = 0;
    int return_value = 0;
    char *search_from = NULL;
    char temp_buffer[1024] = {'\0'};
    char *value_ptr = NULL;


    if (len_sub < 2)
        {
        return(-1);
        }

    double_point = memchr(subject, ':', len_sub);
    if(double_point)
        {
        value_ptr = subject;
        memset(double_point, '\0', 1);
        value = atoi(value_ptr);
        if(value == 0)
            {
            return(-1);
            }
        else
            {
            subject = double_point + 1;
            }
        }
    else
        {
        return(-1);
        }

    subject = tune_subject(subject);

    log_PTR = subject;
    len_sub = f_strlen(&subject[1]);
    if(!len_sub)
        {
        return(-1);
        }
    if(len_sub > len_line)
        {
        return(0);
        }

    if(memcmp(subject, "=", 1) == 0)   /* exact lenght match AND Beginns with */
        {
        error = 0;
        result = strstr(subject_line, &subject[1]);
        if(result)
            {
            return_value = value;
            return(return_value);
            }
        else
            {
            return(return_value);
            }
        }


    if(memcmp(subject, "U", 1) == 0) /*any match and UPPER */
        {
        error = 0;
        for(counter = 0; counter < len_sub; counter++)
            {
            memcpy(&character, &subject[counter + 1], 1);
            character = toupper(character);
            memcpy(&subject[counter + 1], &character, 1);
            }

        result = strstr(subject_line, &subject[1]);
        if(result)
            {
            return_value = value;
            return(return_value);
            }
        else
            {
            return(0);
            }
        }

    if(memcmp(subject, "W", 1) == 0) /*exact alphanumeric and UPPER */
        {
        error = 0;
        for(counter = 0; counter < len_sub; counter++)
            {
            memcpy(&character, &subject[counter + 1], 1);
            character = toupper(character);
            memcpy(&subject[counter + 1], &character, 1);
            }
        result = strstr(subject_line, &subject[1]);
        if(result)
            {
            memcpy(&begin, (result - 1), 1);
            memcpy(&end, &result[len_sub], 1);
            if(isalpha(begin) == 0 && isalpha(end) == 0)
                {
                return_value = value;
                return(return_value);
                }
            else
                {
                return(0);
                }
            }
        else
            {
            return(0);
            }
        }

    if(memcmp(subject, "B", 1) == 0) /* begins and UPPER */
        {
        error = 0;
        for(counter = 0; counter < len_sub; counter++)
            {
            memcpy(&character, &subject[counter + 1], 1);
            character = toupper(character);
            memcpy(&subject[counter + 1], &character, 1);
            }

        result = strstr(subject_line, &subject[1]);
        if(result)
            {
            memcpy(&begin, (result - 1), 1);
            if(isalpha(begin) == 0)
                {
                return_value = value;
                return(return_value);
                }
            else
                {
                return(0);
                }
            }
        else
            {
            return(0);
            }
        }

    if(memcmp(subject, "@", 1) == 0)          /* search for a Emailaddress from the Top Leveldomain*/
        {
        error = 0;
        rest = len_line;
        counter = 0;
        while(rest >= len_sub)
            {
            result = memchr(&subject_line[counter], '@', rest);
            if(result)
                {
                rest = &subject_line[len_line] - result - 1;
                result1 = memchr(result, ' ', rest);
                result2 = memchr(result, '\r', rest);
                result3 = memchr(result, '\"', rest);
                if(result1 && result2)
                    {
                    if(!result3 || (result3 > result2 && result3 > result1))
                        {
                        if(result1 < result2)
                            {
                            search_from = result1 - len_sub;
                            if(strnicmp(search_from, &subject[1], len_sub) == 0)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        else
                            {
                            search_from = result2 - len_sub;
                            if(strnicmp(search_from, &subject[1], len_sub) == 0)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        }
                    }

                if(result1 && result3)
                    {
                    if(!result2 || (result2 > result3 && result2 > result1))
                        {
                        if(result1 < result3)
                            {
                            search_from = result1 - len_sub;
                            if(strnicmp(search_from, &subject[1], len_sub) == 0)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        else
                            {
                            search_from = result3 - len_sub;
                            if(strnicmp(search_from, &subject[1], len_sub) == 0)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        }
                    }

                if(result2 && result3)
                    {
                    if(!result1 || (result1 > result2 && result1 > result3))
                        {
                        if(result3 < result2)
                            {
                            search_from = result3 - len_sub;
                            if(strnicmp(search_from, &subject[1], len_sub) == 0)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        else
                            {
                            search_from = result2 - len_sub;
                            if(strnicmp(search_from, &subject[1], len_sub) == 0)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        }
                    }

                if(result1 && !result2 && !result3)
                    {
                    search_from = result1 - len_sub;
                    if(strnicmp(search_from, &subject[1], len_sub) == 0)
                        {
                        return_value = value;
                        return(return_value);
                        }
                    }

                if(result2 && !result1 && !result3)
                    {
                    search_from = result2 - len_sub;
                    if(strnicmp(search_from, &subject[1], len_sub) == 0)
                        {
                        return_value = value;
                        return(return_value);
                        }
                    }

                if(result3 && !result1 && !result2)
                    {
                    search_from = result3 - len_sub;
                    if(strnicmp(search_from, &subject[1], len_sub) == 0)
                        {
                        return_value = value;
                        return(return_value);
                        }
                    }
                }
            else
                {
                break;
                }
            rest = &subject_line[len_line] - result - 2;
            counter = len_line - rest;
            }
        }

    if(memcmp(subject, "!", 1) == 0)          /* search for a Hyperlink from the Topleveldomain */
        {
        error = 0;
        rest = len_line;
        counter = 0;
        rest -= 7;
        while(rest >= len_sub)
            {
            result = stristr(&subject_line[counter], len_line, "http://", 7);
            if(result)
                {
                result+=7;
                result1 = memchr(result, ' ', rest);
                result5 = memchr(result, '\r', rest);
                result6 = memchr(result, '/', rest);
                if(result1 && result5 && result6)
                    {
                    if(result5 < result1 && result5 < result6)
                        {
                        result1 = result5;
                        }
                    if(result6 < result1 && result6 < result5)
                        {
                        result1 = result6;
                        }
                     }

                else if(!result1 && result5 && result6)
                    {
                    if(result5 < result6)
                        {
                        result1 = result5;
                        }
                    else
                        {
                        result1 = result6;
                        }
                    }

                else if(result5 && result1 && ! result6)
                    {
                    if(result5 < result1)
                        {
                        result1 = result5;
                        }
                    }

                else if(!result5 && result1 && result6)
                    {
                    if(result6 < result1)
                        {
                        result1 = result6;
                        }
                    }

                else if(result5 && !result1 && !result6)
                    {
                    result1 = result5;
                    }

                else if(!result5 && !result1 && result6)
                    {
                    result1 = result6;
                    }



                if(result1)
                    {
                    len = result1 - result;
                    if(len < len_sub)
                        {
                        break;
                        }
                    memcpy(temp_buffer, result, len);

                    result3 = strrchr(&subject[1], '.');
                    if(result3)
                        {
                        compare_len = result3 - &subject[1];
                        result2 = strrchr(temp_buffer, '.');
                        if(result2)
                            {
                            result4 = stristr(&temp_buffer[-compare_len], len, &result3[-compare_len], len_sub);
                            if(result4)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        }
                    else
                        {
                        result2 = strrchr(temp_buffer, '.');
                        if(result2)
                            {
                            result4 = stristr(temp_buffer, len, &subject[1], len_sub);
                            if(result4)
                                {
                                return_value = value;
                                return(return_value);
                                }
                            }
                        }
                    }
                }
            else
                {
                break;
                }
            result += 10;
            counter = result - subject_line;
            if(counter > len_line)
                {
                break;
                }
            rest = len_line - counter;
            }
        }


    result = stristr(subject_line, len_line, &subject[1], len_sub);
    if(result)
        {
        if(memcmp(subject, "*", 1) == 0)    /*any match */
            {
            error = 0;
            return_value = value;
            return(return_value);
            }


        if(memcmp(subject, "w", 1) == 0)    /*exact alpfanumeric match */
            {
            error = 0;
            memcpy(&begin, (result - 1), 1);
            memcpy(&end, &result[len_sub], 1);
            if((isalnum(begin)) && (isalnum(end)))
                {
                if(strnicmp(result, subject + 1, len_sub) == 0)
                    {
                    return_value = value;
                    return(return_value);
                    }
                }

            rest = &subject_line[len_line] - result + 1;
            while(rest >= len_sub)
                {
                result = stristr(&result[len_sub + 1], rest, &subject[1], len_sub);
                if(result)
                    {
                    memcpy(&begin, (result - 1), 1);
                    memcpy(&end, &result[len_sub], 1);
                    if((isalnum(begin) == 0 ) && (isalnum(end) == 0 ))
                        {
                        if(strnicmp(result, subject + 1, len_sub) == 0)
                            {
                            return_value = value;
                            return(return_value);
                            }
                        }
                    }
                else
                    {
                    break;
                    }
                rest = &subject_line[len_line] - result - 1;
                }

            }

        else if(memcmp(subject, "b", 1) == 0)     /*the word must begin with this letters*/
            {
            error = 0;
            if(strnicmp(subject, subject_line, len_sub) == 0)
               {
                return_value = value;
                return(return_value);
                }

            memcpy(&begin, (result - 1), 1);
            if(isalnum(begin) == 0)
                {
                if(strnicmp(result, subject + 1, len_sub) == 0)
                    {
                    return_value = value;
                    return(return_value);
                    }
                }

            rest = &subject_line[len_line] - result - 1;
            while(rest >= len_sub)
                {
                result = stristr(&result[len_sub + 1], rest, &subject[1], len_sub);
                if(result)
                    {
                    memcpy(&begin, (result - 1), 1);
                    if(isalnum(begin) == 0)
                        {
                        if(strnicmp(result, subject + 1, len_sub) == 0)
                            {
                            return_value = value;
                            return(return_value);
                            }
                        }
                    }
                else
                    {
                    break;
                    }
                rest = &subject_line[len_line] - result - 1;
                }
            }
        }

    if(! result)
        {
        error = 0;
        }
    if(error)
        {
        return(-1);
        }
    return(return_value);
    }


int check_ini(int num_file_ini, char *file_buffer_ini, char *entry)
    {
    int counter = 0;
    int rest = 0;
    char *result = NULL;
    int len = 0;

    len = f_strlen(entry);
    rest = num_file_ini;
    while(counter < num_file_ini)
        {
        if(! strnicmp(&file_buffer_ini[counter], entry, len))
            {
            result = strchr(&file_buffer_ini[counter], '=');
            if(result)
                {
                result++;
                return(atoi(result));
                }
            else
                {
                return(0);
                }
            }
        result = memchr(&file_buffer_ini[counter], '\0', rest);
        counter = result - file_buffer_ini;
        rest = num_file_ini - counter;
        if(memcmp(&file_buffer_ini[counter + 1], "\n", 1) == 0)
            {
            counter+=2;
            }
        else
            {
            counter++;
            }
        }
    return(0);
    }

char* check_ini_P(int num_file_ini, char *file_buffer_ini, char *entry)
    {
    int counter = 0;
    int rest = 0;
    char *result = NULL;
    int len = 0;

    len = f_strlen(entry);
    rest = num_file_ini;
    while(counter < num_file_ini)
        {
        if(! strnicmp(&file_buffer_ini[counter], entry, len))
            {
            result = strchr(&file_buffer_ini[counter], '=');
            if(result)
                {
                result++;
                if(memcmp(result, "\0", 1) == 0)
                    {
                    return(NULL);
                    }
                return(result);
                }
            else
                {
                return(NULL);
                }
            }
        result = memchr(&file_buffer_ini[counter], '\0', rest);
        counter = result - file_buffer_ini;
        rest = num_file_ini - counter;
        if(memcmp(&file_buffer_ini[counter + 1], "\n", 1) == 0)
            {
            counter+=2;
            }
        else
            {
            counter++;
            }
        }
    return(NULL);
    }


int track_mail(ULONG IP, char *Domain, char *sender, int bann_time, int bombing_amount, int bombing_time)
    {
    int block_adress = 0;
    int begin_Domain_block = 0;
    int begin_IP_block = 0;
    int begin_Sender_block = 0;
    int buffer_size = 0;
    int counter = 0;
    int counter1 = 0;
    int counter2 = 0;
    int data = 0;
    char *file_buffer = NULL;

    int file_handle = 0;
    int file_size = 0;
    int first_entry = 0;
    int hours = 0;
    char *IP_buffer = NULL;
    int ip_copied = 0;
    int IP_buffer_counter = 0;
    int len = 0;

    int new_offset = 0;
    int new_track = 0;
    int next = 0;
    int next_IP = 0;
    int number_of_entrys = 0;
    int number_of_IPs = 0;
    int number_of_Domains = 0;
    int number_of_sender = 0;
    int num_file = 0;
    int num_written = 0;
    int old_counter = 0;
    int old_IP_buffer_counter = 0;
    int pos_of_time_track_counter = 0;
    int pos_of_new_domain = 0;
    int pos_of_new_sender = 0;
    int old_next = 0;
    int return_value = -1;
    FILE *stream = NULL;
    int time_track_counter = 0;
    int temp = 0;
    int temp1 = 0;
    int temp_counter = 0;
    time_t ltime = 0;
    time_t temp_time = 0;
    time_t temp_time1 = 0;


    time(&ltime);
   /* Convert it to the structure tm */
   newtime = localtime(&ltime);




    /* bakupcopie; */
    file_handle = open("tracking",  O_CREAT | O_RDWR | O_TEXT, S_IREAD | S_IWRITE);             /*Datei zum Lesen îffnen*/
    if(file_handle == -1)                                              /*Fehler */
        {
        if(errortracking)
            {
            stream = fopen(log_path_error,"a");
            fprintf(stream, "%s %i, \n", asctime(newtime), errno);
            fclose(stream);
            close(file_handle);                                            /* Datei Schliessen*/
            exit(0);
            }
        }


    file_size = filelength(file_handle);

    if(file_size == -1L)                                /* Grîsse Åbergeben*/
        {
        if(errortracking)
            {
            stream = fopen(log_path_error,"a");
            fprintf(stream,"%s %i, \n", asctime(newtime), errno);
            printf("Unable to determine length of tracking.\n");
            fclose(stream);
            close(file_handle);                                            /* Datei Schliessen*/
            return(0);
            }
        }

    buffer_size = file_size;
    file_buffer = (char*) calloc(++buffer_size, sizeof(char));            /*speicher reservieren*/
    if(file_buffer == NULL)                                      /*bei einem Fehler*/
        {
        stream = fopen(log_path_error,"a");
        fprintf(stream, "%s %i, \n", asctime(newtime), errno);
        fclose(stream);
        close(file_handle);                                            /* Datei Schliessen*/
        return(0);
        }

    num_file = read(file_handle, file_buffer, file_size);       /* Datei einlesen  num = die eingelesenen Zeilen*/
    memset(&file_buffer[num_file], '\0', 1);
    IP_buffer = (char*) calloc(buffer_size + 1024, sizeof(char));            /*speicher reservieren*/
    if(IP_buffer == NULL)                                      /*bei einem Fehler*/
        {
        stream = fopen(log_path_error,"a");
        fprintf(stream, "%s %i, \n", asctime(newtime), errno);
        fclose(stream);
        close(file_handle);                                            /* Datei Schliessen*/
        return(0);
        }

    memcpy(&temp_time1, &ltime, sizeof(double));


    if(!file_size)
        {
        temp = 24;
        memcpy(&IP_buffer[0], &temp, 4); /*begin IP*/
        temp = 1;
        memcpy(&IP_buffer[4], &temp, 4); /*number of IPs*/
        temp = 32 + sizeof(double);
        memcpy(&IP_buffer[8], &temp, 4); /*begin Doamins*/
        temp = 1;
        memcpy(&IP_buffer[12], &temp, 4); /*number of Domains*/
        len = f_strlen(Domain);
        len++;
        temp = len + 44 + sizeof(double);
        memcpy(&IP_buffer[40], &temp, 4); /*Doamin pointer to the next Domain*/
        memcpy(&IP_buffer[44], Domain, len); /*Doamin copy in Buffer*/
        temp1 = len + 44;

        memcpy(&IP_buffer[temp1], &ltime, sizeof(double));

        memcpy(&IP_buffer[16], &temp, 4);     /*Pointer to the sender part*/
        len = f_strlen(sender);
        len++;
        temp1 = temp + 4 + len + 8;
        temp += 4;
        memcpy(&IP_buffer[temp], sender, len);
        temp -= 4;
        memcpy(&IP_buffer[temp], &temp1, 4);
        temp = 1;
        memcpy(&IP_buffer[20], &temp, 4);
        number_of_entrys = 1;
        memcpy(&IP_buffer[24], &number_of_entrys, 4);
        memcpy(&IP_buffer[28], &IP, 4);
        memcpy(&IP_buffer[32], &ltime, sizeof(double));
        memcpy(&IP_buffer[temp1 - 8], &ltime, sizeof(double));
        temp1 += sizeof(double);

        num_written = write(file_handle, IP_buffer, temp1);


        }
    else
        {
        memcpy(&begin_IP_block, &file_buffer[0], 4);
        memcpy(&number_of_IPs, &file_buffer[4], 4);
        memcpy(&begin_Domain_block, &file_buffer[8], 4);
        memcpy(&number_of_Domains, &file_buffer[12], 4);
        memcpy(&begin_Sender_block, &file_buffer[16], 4);
        memcpy(&number_of_sender, &file_buffer[20], 4);
        memcpy(&data, &file_buffer[begin_IP_block], 4);
        IP_buffer_counter = 24;
        counter = begin_IP_block;
        block_adress = begin_IP_block;

        return_value = memcmp(&file_buffer[counter + 4], &IP, 4);  /* nur den ersten Wert vergleichen und speziell behandeln     */
        counter2 = 0;
        if (return_value < 0)  /* nur wenn neu*/
            {
            next_IP = IP_buffer_counter + 16;
            memcpy(&IP_buffer[IP_buffer_counter], &next_IP, 4);
            IP_buffer_counter += 4;
            memcpy(&IP_buffer[IP_buffer_counter], &IP, 4);
            IP_buffer_counter+= 4;
            memcpy(&IP_buffer[IP_buffer_counter], &ltime, sizeof(double));
            number_of_IPs++;
            IP_buffer_counter += 8;
            new_track = 1;
            }


        do
            {
            old_counter = counter;
            old_IP_buffer_counter = IP_buffer_counter;

            return_value = memcmp(&file_buffer[counter + 4], &IP, 4);  /* nur den ersten Wert vergleichen und speziell behandeln     */
            counter2 = 0;

            if(return_value == 0)
                {
                memcpy (&number_of_entrys, &file_buffer[counter], sizeof(int));
                counter += 8;
                IP_buffer_counter = block_adress + 8;
                do
                    {
                    memcpy(&temp_time, &file_buffer[counter], 8);
                    hours = (temp_time1 - temp_time) / 3600;
                    if(hours < bombing_time)
                        {
                        time_track_counter++;
                        if(time_track_counter >= bombing_amount)
                            {
                            bann_IP(IP, bann_time);
                            counter = old_counter;
                            IP_buffer_counter = old_IP_buffer_counter;
                            counter2 = number_of_entrys;
                            }
                        else
                            {
                            memcpy(&IP_buffer[IP_buffer_counter], &temp_time, 8);
                            IP_buffer_counter += 8;
                            counter += 8;
                            }
                        }
                    else         /* kein else */
                        {
                        counter += 8;   /*Werte ÅberprÅfen*/
                        }
                    counter2++;

                    /*EinfÅgen, wenn der letze */

                    } while(counter2 < number_of_entrys);

                /* if funktion*/
                if(time_track_counter < bombing_amount)
                    {
                    memcpy(&IP_buffer[IP_buffer_counter], &temp_time1, 8);
                    memcpy(&IP_buffer[block_adress], &IP_buffer_counter, 4);
                    memcpy(&IP_buffer[block_adress + 4], &IP, 4);
                    IP_buffer_counter += 8;
                    block_adress = IP_buffer_counter;
                    }
                new_track = 1;
                }
            else
                {
                memcpy(&temp_time, &file_buffer[counter], 8);
                hours = (temp_time1 - temp_time) / 3600;
                if(hours < bombing_time)
                    {
                    memcpy(&IP_buffer[IP_buffer_counter], &temp_time, 8);
                    IP_buffer_counter += 8;
                    counter += 8;
                    }
                else         /* kein else */
                    {
                    counter += 8;   /*Werte ÅberprÅfen*/
                    }
                }


            counter1++;
            } while (counter1 < number_of_IPs);

        if(! new_track)
            {
            block_adress = 24 + 4 * counter1;
            memcpy(&IP_buffer[block_adress], &IP_buffer_counter, 4);
            memcpy(&IP_buffer[IP_buffer_counter], &IP, 4);
            IP_buffer_counter += 4;
            memcpy(&IP_buffer[IP_buffer_counter], &first_entry, 4);
            IP_buffer_counter+= 4;
            IP_buffer_counter+= 4;
            memcpy(&IP_buffer[IP_buffer_counter], &ltime, sizeof(double));
            IP_buffer_counter += sizeof(double);
            }

        /* IP_block kopieren */
        temp_counter = 0;
        memcpy(&IP_buffer[4], &IP_buffer_counter, 4);



        /* Domain Part */
        counter1 = 0;
        len = f_strlen(Domain);
        len++;
        do
            {
            old_counter = counter;
            old_IP_buffer_counter = IP_buffer_counter;
            counter2 = 0;
            time_track_counter = 0;
            return_value = memcmp(&file_buffer[counter + 4], Domain, len);
            if (return_value < 0)
                {
                next = IP_buffer_counter + len + 8;
                memcpy(&IP_buffer[IP_buffer_counter], &next, 4);
                IP_buffer_counter += 4;
                memcpy(&IP_buffer[IP_buffer_counter], Domain, len);
                IP_buffer_counter += len;
                memcpy(&IP_buffer[IP_buffer_counter], &ltime, sizeof(double));
                IP_buffer_counter += sizeof(double);
                number_of_Domains++;
                }
            if(return_value == 0)
                {
                memcpy (&next, &file_buffer[counter], sizeof(int));
                number_of_entrys = (next - len - counter - 4) / 8 ;
                counter += 4;
                pos_of_new_domain = IP_buffer_counter;
                IP_buffer_counter += len + 4;
                do
                    {
                    memcpy(&temp_time, &file_buffer[counter + len], 8);
                    hours = (temp_time1 - temp_time) / 3600;
                    if(hours < bombing_time)
                        {
                        time_track_counter++;
                        if(time_track_counter >= bombing_amount)
                            {
                            bann_Domain(Domain, bann_time);
                            counter = old_counter;
                            IP_buffer_counter = old_IP_buffer_counter;
                            counter2 = number_of_entrys;
                            }
                        else
                            {
                            memcpy(&IP_buffer[IP_buffer_counter], &file_buffer[counter + len], 8);
                            IP_buffer_counter += 8;
                            counter += 8;
                            }
                        }
                    else
                        {
                        counter += 8;
                        }
                    counter2++;

                    } while(counter2 < number_of_entrys);

                if(time_track_counter < bombing_amount)
                    {
                    memcpy(&IP_buffer[IP_buffer_counter], &temp_time1, 8);
                    IP_buffer_counter += 8;
                    memcpy(&IP_buffer[pos_of_new_domain], &IP_buffer_counter, 4);
                    memcpy(&IP_buffer[pos_of_new_domain + 4], Domain, len);
                    block_adress = IP_buffer_counter;
                    }
                }
            if(return_value > 0)
                {
                block_adress = 24 + 4 * counter1;
                memcpy(&IP_buffer[block_adress], &IP_buffer_counter, 4);
                memcpy(&IP_buffer[IP_buffer_counter], &IP, 4);
                IP_buffer_counter += 4;
                memcpy(&IP_buffer[IP_buffer_counter], &first_entry, 4);
                IP_buffer_counter+= 4;
                IP_buffer_counter+= 4;
                memcpy(&IP_buffer[IP_buffer_counter], &ltime, sizeof(double));
                IP_buffer_counter += sizeof(double);
                }
            counter1++;
            }while (counter1 < number_of_Domains);

        /*sender Part */

/*
 stream = fopen("c:\\domain.txt","a");
    fwrite(IP_buffer, 1, 200, stream);
fclose(stream);

*/
        counter1 = 0;
        len = f_strlen(sender);
        len++;
        do
            {
            old_counter = counter;
            old_IP_buffer_counter = IP_buffer_counter;
            counter2 = 0;
            time_track_counter = 0;
            return_value = memcmp(&file_buffer[next + 4], sender, len);
            if (return_value < 0)
                {
                next = IP_buffer_counter + len + 8;
                memcpy(&IP_buffer[IP_buffer_counter], &next, 4);
                IP_buffer_counter += 4;
                memcpy(&IP_buffer[IP_buffer_counter], sender, len);
                IP_buffer_counter += len;
                memcpy(&IP_buffer[IP_buffer_counter], &ltime, sizeof(double));
                IP_buffer_counter += sizeof(double);
                number_of_sender++;
                }
            if(return_value == 0)
                {
                old_next = next;
                memcpy (&next, &file_buffer[next], sizeof(int));
                number_of_entrys = (next - len - old_next - 4) / 8 ;
                counter += 4;
                pos_of_new_sender = IP_buffer_counter;
                IP_buffer_counter += len + 4;
                do
                    {
                    memcpy(&temp_time, &file_buffer[old_next + 4 + len], 8);
                    hours = (temp_time1 - temp_time) / 3600;
                    if(hours < bombing_time)
                        {
                        time_track_counter++;

                        if(time_track_counter >= bombing_amount)
                            {
                            bann_sender(sender, bann_time);
                            counter = old_counter;
                            IP_buffer_counter = old_IP_buffer_counter;
                            counter2 = number_of_entrys;
                            }
                        else
                            {
                            memcpy(&IP_buffer[IP_buffer_counter], &file_buffer[old_next + 4 + len + counter2 * 8], 8);
                            IP_buffer_counter += 8;
                            counter += 8;
                            }
                        }
                    else
                        {
                        counter += 8;
                        }
                    counter2++;

                    } while(counter2 < number_of_entrys);

                if(time_track_counter < bombing_amount)
                    {
                    memcpy(&IP_buffer[IP_buffer_counter], &temp_time1, 8);
                    IP_buffer_counter += 8;
                    memcpy(&IP_buffer[block_adress], &IP_buffer_counter, 4);
                    memcpy(&IP_buffer[block_adress + 4], sender, len);
                    block_adress = IP_buffer_counter;
                    }
                }
            if(return_value > 0)
                {
                block_adress = 24 + 4 * counter1;
                memcpy(&IP_buffer[block_adress], &IP_buffer_counter, 4);
                memcpy(&IP_buffer[IP_buffer_counter], &IP, 4);
                IP_buffer_counter += 4;
                memcpy(&IP_buffer[IP_buffer_counter], &first_entry, 4);
                IP_buffer_counter+= 4;
                IP_buffer_counter+= 4;
                memcpy(&IP_buffer[IP_buffer_counter], &ltime, sizeof(double));
                IP_buffer_counter += sizeof(double);
                }
            counter1++;
            }while (counter1 < number_of_sender);
        lseek(file_handle, 0, SEEK_SET);
        write(file_handle, IP_buffer, IP_buffer_counter);
        }


    close(file_handle);
    return(0);
    /*close file
    del backupfile */
    }


int test_of_empty_subject(char *subject, int empty_subject, int min_subject)
    {
    int len = 0;
    len = f_strlen(subject);
    if(len == 0)
        {
        return(empty_subject);
        }
    if(len < min_subject)
        {
        return(empty_subject);
        }
    if((stricmp("Re:", subject) == 0) && len < 5)
        {
        return(empty_subject);
        }
    if((stricmp("FWD: ", subject) == 0) && len < 6)
        {
        return(empty_subject);
        }
    return(0);
    }


int check_empty_body(char *body, int len_body, char *boundary_ptr, int empty_body)
    {
    char *multipart = NULL;
    int len_boundary = 0;
    int rest = 0;
    char *result = NULL;

    len_boundary = f_strlen(boundary_ptr);
    len_boundary--;

    multipart = stristr(body, len_body, boundary_ptr, len_boundary);
    if(!multipart)
        {
        return(0);
        }

    rest = &body[len_body] - &multipart[len_boundary];
    result = stristr(multipart, rest, "\r\n\r\n", 4);
    result+=4;
    rest = &body[len_body] - result;
    if(rest < 4)
        {
        return(empty_body);
        }
    multipart = stristr(result, rest, boundary_ptr, len_boundary);
    if(!multipart)
        {
        return(empty_body);
        }
    rest = &body[len_body] - &multipart[len_boundary];
    result = stristr(&multipart[len_boundary], rest, "\r\n\r\n", 4);
    if(!result)
        {
        return(empty_body);
        }
    result+=4;
    if(result > &body[len_body])
        {
        return(empty_body);
        }
    rest = &body[len_body] - result;
    if(rest < 4)
        {
        return(empty_body);
        }

    return(0);

    }



/*
** decodeblock
**
** decode 4 '6-bit' characters into 3 8-bit binary bytes
*/
void decodeblock( unsigned char in[4], unsigned char out[3] )
{
    out[ 0 ] = (in[0] << 2) | (in[1] >> 4);
    out[ 1 ] = (in[1] << 4) | (in[2] >> 2);
    out[ 2 ] = (in[2] << 6) | (in[3]);
}

/*
** decode
**
** decode a base64 encoded stream discarding padding, line breaks and noise
*/

int decode(char *inbuffer, int len_buffer, char *outbuffer, int *size_out_buffer )
    {
    /*
    ** Translation Table to decode (created by author)
    */
    unsigned char in[4], v;
    unsigned char out[4] = {'\0'};
    int counter = 0;
    int i = 0;
    int len = 0;
    int stop = 0;
    int ret = 0;
    int size = 0;

    memcpy(&size, size_out_buffer, 4);

    while( counter < len_buffer && !stop)
        {
        for( len = 0, i = 0, ret = 0; i < 4 && counter < len_buffer; i++ )
            {
            v = 255;
            while( counter < len_buffer && v == 255 && ! stop)
                {
                memcpy(&v, &inbuffer[counter], 1);
                if(v == '\r' || v == '\n')
                    {
                    if(memcmp(&inbuffer[counter], "\r\n\r\n", 4) == 0 && size)
                        {
                        stop++;
                        break;
                        }
                    if(memcmp(&inbuffer[counter], "\r\r", 2) == 0 && size)
                        {
                        stop++;
                        break;
                        }
                    if(memcmp(&inbuffer[counter], "\n\n", 2) == 0 && size)
                        {
                        stop++;
                        break;
                        }

                    }
                if(v < 43 || v > 122)
                    {
                    counter++;
                    v = 255;
                    continue;
                    }
                if(v > 64 && v < 91)
                    {
                    v -= 65;
                    }
                else if(v > 96 && v < 123 )
                    {
                    v -= 71;
                    }
                else if(v > 47 && v < 58)
                    {
                    v += 4;
                    }
                else if(v == 43)
                    {
                    v = 62;
                    }
                else if(v == 47)
                    {
                    v = 63;
                    }
                else if(v == 61)
                    {
                    v = 0;
                    stop++;
                    }
                counter++;
                }

            if( counter < len_buffer)
                {
                len++;
                in[ i ] = (v);
                }
            }
        if( len )
            {
            decodeblock( in, out );
            memcpy(&outbuffer[size], &out, 3);
            if(stop == 1)
                {
                size += 2;
                }
            else if(stop == 2)
                {
                size += 1;
                }
            else
                {
                size += 3;
                }
            }

        }
    memcpy(size_out_buffer, &size, 4);
    return(size);
    }



int bann_Domain(char *Domain, int bann_time)
    {
    time_t ltime = 0;
    char time_buffer[8];
    int len = 0;
    int file_handle = 0;
    char time_out_buffer[24] = {'\0'};
    len = strlen(Domain);
    len++;
    file_handle = open("blacklist_domain_temp", O_CREAT | O_TEXT | O_RDWR, S_IREAD | S_IWRITE);             /*Datei zum Lesen îffnen*/
    lseek(file_handle, 0, SEEK_END);
    write(file_handle, Domain, len);
    time(&ltime);
    memcpy(time_buffer, &ltime, 8);
    encode(time_buffer, time_out_buffer, 72, 24 );
    len = strlen(time_buffer);
    write(file_handle, time_buffer, len);

    write(file_handle, "\n", 1);
    close(file_handle);
    return(0);

    }

int bann_sender(char *sender, int bann_time)
    {
    time_t ltime = 0;
    char time_buffer[8];
    int len = 0;
    int file_handle = 0;
    char time_out_buffer[24] = {'\0'};
    len = strlen(sender);
    len++;
    file_handle = open("blacklist_sender_temp", O_CREAT | O_TEXT | O_RDWR, S_IREAD | S_IWRITE);             /*Datei zum Lesen îffnen*/
    lseek(file_handle, 0, SEEK_END);
    write(file_handle, sender, len);
    time(&ltime);
    memcpy(time_buffer, &ltime, 8);
    encode(time_buffer, time_out_buffer, 72, 24 );
    len = strlen(time_buffer);
    write(file_handle, time_buffer, len);

    write(file_handle, "\n", 1);
    close(file_handle);
    return(0);


    }

int bann_IP(ULONG IP, int bann_time)
    {
    time_t ltime = 0;
    char time_buffer[8];
    char ip_as_string[24] = {'\0'};
    int len = 0;
    int file_handle = 0;
    ulong_2_ip(IP, ip_as_string);
    len = strlen(ip_as_string);
    len++;
    file_handle = open("blacklist_temp", O_CREAT | O_TEXT | O_RDWR, S_IREAD | S_IWRITE);             /*Datei zum Lesen îffnen*/
    lseek(file_handle, 0, SEEK_END);
    write(file_handle, ip_as_string, len);
    memset(ip_as_string, '\0', 24);
    time(&ltime);
    memcpy(time_buffer, &ltime, 8);
    encode(time_buffer, ip_as_string, 72, 24 );
    len = strlen(ip_as_string);
    write(file_handle, ip_as_string, len);

    write(file_handle, "\n", 1);
    close(file_handle);
    return(0);
    }



char *ulong_2_ip(ULONG IP, char *whole)
    {
    int len = 0;
    int pos = 0;
    int part;
    char temp[4] = {'\0'};
    part = IP & 4278190080;
    memset(whole, '[', 1);
    ultoa(part, temp, 10);
    len = strlen(temp);
    memcpy(&whole[1], temp, len);
    pos = len + 1;
    memset(&whole[pos], '.', 1);
    pos++;
    part = IP & 16711680;
    ultoa(part, temp, 10);
    len = strlen(temp);
    memcpy(&whole[pos], temp, len);
    pos += len;
    memset(&whole[pos], '.', 1);
    pos++;
    part = IP & 65280;
    ultoa(part, temp, 10);
    len = strlen(temp);
    memcpy(&whole[pos], temp, len);
    pos += len;
    memset(&whole[pos], '.', 1);
    part = IP & 255;
    ultoa(part, temp, 10);
    len = strlen(temp);
    memcpy(&whole[pos], temp, len);
    pos += len;
    memset(&whole[pos], ']', 1);
    memset(&whole[pos + 1], '\0', 1);
    return(whole);
    }

/*
** encodeblock
**
** encode 3 8-bit binary bytes as 4 '6-bit' characters
*/
void encodeblock( unsigned char in[3], unsigned char out[4], int len )
    {
    static const char cb64[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    out[0] = cb64[ in[0] >> 2 ];
    out[1] = cb64[ ((in[0] & 0x03) << 4) | ((in[1] & 0xf0) >> 4) ];
    out[2] = (unsigned char) (len > 1 ? cb64[ ((in[1] & 0x0f) << 2) | ((in[2] & 0xc0) >> 6) ] : '=');
    out[3] = (unsigned char) (len > 2 ? cb64[ in[2] & 0x3f ] : '=');
    }

/*
** encode
**
** base64 encode a stream adding padding and line breaks as per spec.
*/
void encode(char *inbuffer, char* outbuffer, int linesize, int buffer_size )
    {
    unsigned char in[3] = {'\0'};
    unsigned char out[4] = {'\0'};
    int i = 0;
    int len = 0;
    int blocksout = 0;
    int counter = 0;
    while( counter < 8 )
         {
        len = 0;
        for( i = 0; i < 3; i++ )
            {
            memcpy(&in[i], &inbuffer[i], 1);
            if( counter < 8 )
                {
                len++;
                }
            else
                {
                in[i] = 0;
                }
            }
        if( len )
            {
            encodeblock( in, out, len );
            for( i = 0; i < 4; i++ )
                {
                memcpy(&outbuffer[i], &out[i], 1);
                }
            blocksout++;
            }
        if( blocksout >= (linesize/4) || counter == 8 )
            {
            if( blocksout )
                {
                sprintf( outbuffer, "\r\n" );
                }
            blocksout = 0;
            }
        counter;
        }
    }

int comp_domain(char *domain, char *domain1)
    {
    char *result = NULL;
    char *result1 = NULL;
    int len_domain = 0;
    int len_domain1 = 0;
    int tld = 0;
    int value = 0;

    if(memcmp(domain, "*", 1) == 0)     /*  *.cc  */
            {
            domain += 2;
            tld = 1;
            }


    result = strrchr(domain, '.');
    if(result)
        {
        result++;
        if(memcmp(result, "*", 1) == 0)
            {
            tld = -1;
            result--;                    /*  domain.*  */
            memset(result, '\0', 1);
            result = strrchr(domain, '.');
            if(result)
                {
                if(memicmp(result, "com", 3) == 0)
                    {
                    memset(result, '\0', 1);
                    }
                else if(memicmp(result, "net", 3) == 0)
                    {
                    memset(result, '\0', 1);
                    }
                else if(memicmp(result, "co", 2) == 0)
                    {
                    memset(result, '\0', 1);
                    }
                else if(memicmp(result, "biz", 3) == 0)
                    {
                    memset(result, '\0', 1);
                    }
                }
            }
        }

    result1 = strrchr(domain1, '.');
    if(tld == -1)                          /* domain.* */
        {
        memset(result1, '\0', 1);
        result1 = strrchr(domain1, '.');
        if(result1)
            {
            if(memicmp(result1, "com", 3) == 0)
                {
                memset(result1, '\0', 1);
                }
            else if(memicmp(result1, "net", 3) == 0)
                {
                memset(result1, '\0', 1);
                }
            else if(memicmp(result1, "co", 2) == 0)
                {
                memset(result1, '\0', 1);
                }
            else if(memicmp(result1, "biz", 3) == 0)
                {
                memset(result1, '\0', 1);
                }
            }
        result1 = strrchr(domain1, '.');
        if(result1)
            {
            domain1 = result1;
            }
        }


    if(tld == 1)                   /*   *.cc   */
        {
        domain1 = result1++;
        }


    len_domain = f_strlen(domain);
    len_domain1 = f_strlen(domain1);
    if(len_domain1 < len_domain)
        {
        return(1);
        }
    else
        {
        strrev(domain);
        strrev(domain1);
        value = (strnicmp(domain, domain1, len_domain));
        return(value);
        }

    }

char* stristr(char* string, int string_len, char* substring, int substring_len)
    {
    int character = 0;
    int character1 = 0;
    int rest = 0;
    int counter = 0;
    char *result = NULL;
    char *result1 = NULL;
    char *result2 = NULL;
    char *short_string = NULL;
    int str_counter = 0;

    rest = string_len;
    short_string = malloc(substring_len + 1);
    memcpy(short_string, substring, substring_len);
    memcpy(&character, short_string, 1);

    str_counter = 0;

    memcpy(&character, &substring[str_counter], 1);
    character = tolower(character);
    memcpy(&short_string[str_counter], &character, 1);


    memset(&short_string[substring_len], '\0', 1);
    memcpy(&character1, &short_string[0], 1);
    while(rest >= substring_len)
        {
        result = memchr(&string[counter], character1, rest);
        if(result)
            {
            if((memicmp(short_string, result, substring_len)) == 0)
                {
                free(short_string);
                result1 = result;
                break;
                }
            rest = string_len - (result - string);
            rest--;
            counter = string_len - rest;
            continue;
            }
        if(!result)
            {
            break;
            }
        }

    str_counter = 0;

    memcpy(&character, &substring[str_counter], 1);
    character = toupper(character);
    memcpy(&short_string[str_counter], &character, 1);


    memcpy(&character1, &short_string[0], 1);
    rest = string_len;
    counter = 0;
    while(rest >= substring_len)
        {
        result = memchr(&string[counter], character1, rest);
        if(result)
            {
            if((memicmp(short_string, result, substring_len)) == 0)
                {
                free(short_string);
                result2 = result;
                break;
                }
            rest = string_len - (result - string);
            rest--;
            counter = string_len - rest;

            continue;
            }
        if(!result)
            {
            break;
            }
        }

    free(short_string);
    if(result1 && !result2)
        {
        return(result1);
        }
    if(!result1 && result2)
        {
        return(result2);
        }
    if(!result1 && !result2)
        {
        return(NULL);
        }
    if(result1 < result2)
        {
        return(result1);
        }
    else
        {
        return(result2);
        }

    }


int test_ip_link(char* body, int rest)
    {
    int counter = 0;
    int for_counter = 0;
    int for_counter1 = 0;
    int leave = 0;
    int len = 0;
    int number = 0;
    int number1 = 0;
    int ip = 0;
    char *result = NULL;
    char *result2 = NULL;
    char *result1 = NULL;
    int body_size = 0;
    FILE *stream = NULL;
    char temp_buffer[512] = {'\0'};
    char temp_buffer1[4] = {'\0'};
    int temp_len = 0;
    body_size = rest;

    while(rest >= 7 && ip != 4)
        {
        result = stristr(&body[counter], rest, "http://", 7);
        if(result)
            {
            result1 = result + 7;
            for(leave = 0, ip = 0, for_counter = 0; for_counter < 4 && ! leave; for_counter++)
                {
                result2 = memchr(result1, '.', 4);
                if(!result2 && ip == 3)
                    {
                    for(for_counter1 = 0, len = 0; for_counter1 < 3; for_counter1++, len++)
                        {
                        memset(temp_buffer1, '\0', 4);
                        memcpy(temp_buffer1, result1 + for_counter1, 1);
                        number1 = atoi(temp_buffer1);
                        if(! number1)
                            {
                            break;
                            }
                        }
                    if(len)
                        {
                        result2 = result1 + len;
                        }
                    }

                else if(!result2)
                    {
                    rest = &body[body_size] - &result[7];
                    break;
                    }

                if(result2)
                    {
                    temp_len = result2 - result1;
                    memset(temp_buffer, '\0', 256);
                    memcpy(temp_buffer, result1, temp_len);
                    if(temp_len == 1 && memcmp(temp_buffer, "0", 1) == 0)
                        {
                        ip++;
                        result1 = result2 + 1;
                        continue;
                        }
                    number = atoi(temp_buffer);
                    if(number > 0 && number < 256)
                        {
                        ip++;
                        result1 = result2 + 1;
                        continue;
                        }
                    else
                        {
                        leave = 1;
                        }
                    }
                }
            counter = &result[7] - body;
            rest = body_size - counter;
            }
        else
            {
            break;
            }
        }
    if(ip == 4)
        {
        if(logging)
            {
            temp_len = result2 - result;
            memset(temp_buffer, '\0', 256);
            memcpy(temp_buffer, result, temp_len);
            stream = fopen(log_path,"a");
            fprintf(stream, "Direct IP-Link[%s]\n", temp_buffer);
            fclose(stream);
            }
        return(temp_len);
        }
    else
        {
        return(0);
        }
    }

char* tune_subject(char* subject)
    {
    int counter = 0;
    int fill = 0;
    int len = 0;
    int move = 0;
    int rest = 0;
    int result = 5;
    char *resultat = NULL;

    len = f_strlen(subject);

    resultat = memchr(subject, ' ', len);
    if(resultat)
        {
        while(counter < len)
            {
            result = memcmp(&subject[counter], " ", 1);
            if(result)
                {
                break;
                }
            else
                {
                counter++;
                move =1;
                }
            }
        if(move)
            {
            rest = len - counter;
            memmove(subject, &subject[counter], rest);
            fill = &subject[counter] - subject;
            memset(&subject[len - fill], '\0', 1);
            len = len - fill;
            counter = 1;
            move = 0;
            }
        else
            {
            rest = len;
            counter = 1;
            }


        while(counter < len)
            {
            result = memcmp(&subject[counter], " ", 1);
            if(result)
                {
                break;
                }
            else
                {
                counter++;
                move = 1;
                }
            }
        if(move)
            {
            rest = len - counter;
            memmove(&subject[1], &subject[counter], rest);
            fill = &subject[counter] - subject;
            memset(&subject[len - fill + 1], '\0', 1);
            len = len - fill;
            counter = len;
            }
        else
            {
            rest = len - 1;
            move = 0;
            counter = len -1;
            }


        while(counter)
            {
            result = memcmp(&subject[counter], " ", 1);
            if(!result)
                {
                counter--;
                }
            else
                {
                counter++;
                memset(&subject[counter], '\0', 1);
                break;
                }
            }
        }
    return(subject);
    }


char* tune_mailadress(char* mailadress)
    {
    int counter = 0;
    int fill = 0;
    int len = 0;
    int move = 0;
    int rest = 0;
    int result = 5;
    char *resultat = NULL;

    len = f_strlen(mailadress);

    resultat = memchr(mailadress, ' ', len);
    if(resultat)
        {
        while(counter < len)
            {
            result = memcmp(&mailadress[counter], " ", 1);
            if(result)
                {
                break;
                }
            else
                {
                counter++;
                move =1;
                }
            }
        if(move)
            {
            rest = len - counter;
            memmove(mailadress, &mailadress[counter], rest);
            fill = &mailadress[counter] - mailadress;
            memset(&mailadress[len - fill], '\0', 1);
            len = len - fill;
            counter = 1;
            move = 0;
            }
        else
            {
            rest = len;
            counter = 1;
            }


        while(counter < len)
            {
            result = memcmp(&mailadress[counter], " ", 1);
            if(result)
                {
                break;
                }
            else
                {
                counter++;
                move = 1;
                }
            }
        if(move)
            {
            rest = len - counter;
            memmove(&mailadress[1], &mailadress[counter], rest);
            fill = &mailadress[counter] - mailadress;
            memset(&mailadress[len - fill + 1], '\0', 1);
            len = len - fill;
            counter = len;
            }


        resultat = memchr(mailadress, ' ', len);
        if(resultat)
            {
            memset(resultat, '\0', 1);
            }
        }
    return(mailadress);
    }


int test_mail_addres(char* subject_line, int len_line, char* subject, int len_sub, int value)
    {
    int character = 0;
    int counter = 0;
    int dummi = 0;
    char *double_point = NULL;
    int len_counter = 0;
    char *mailadress = NULL;
    int rc = 1;
    char *result = NULL;
    char *slash_ptr = NULL;
    char *value_ptr = NULL;


    double_point = memchr(subject, ':', len_sub);
    if(double_point)
        {
        value_ptr = subject;
        memset(double_point, '\0', 1);
        value = atoi(value_ptr);
        if(value == 0)
            {
            return(-2);
            }
        else
            {
            subject = double_point + 1;
            }
        }
    else
        {
        return(-2);
        }

    len_sub = f_strlen(&subject[1]);
    if(!len_sub)
        {
        return(-2);
        }
    mailadress = (char*) calloc(len_sub, sizeof(char));            /*speicher reservieren*/
    memcpy(mailadress, subject, len_sub);
    tune_mailadress(mailadress);


    log_PTR = mailadress;
    len_sub = f_strlen(&mailadress[1]);
    if(!len_sub)
        {
        free(mailadress);
        return(-2);
        }

    slash_ptr = memchr(mailadress, 47, len_sub);
    if(slash_ptr)
        {
        for(len_counter = 0; len_counter < len_sub; len_counter++)
            {
            memcpy(&character, &mailadress[len_counter], 1);
            dummi = isgraph(character);
            if(!dummi)
                {
                len_counter--;
                break;
                }
            }
        }


    if(len_counter)
        {
        len_sub = len_counter;
        }
    if(memcmp(mailadress, "@", 1) == 0)
        {
        result = stristr(&subject_line[len_line - len_sub - 1], len_sub, subject, len_sub);
        }
    else if(memcmp(subject, "!",1) == 0)
        {
        if(len_sub > len_line)
            {
            free(mailadress);
            return(0);
            }
        result = stristr(&subject_line[len_line - len_sub], len_line, &subject[1], len_sub);
        if(result)
            {
            result--;
            if((memcmp(result,"@", 1) == 0) || (memcmp(result, ".", 1) == 0))
                {
                result++;
                }
            else
                {
                result = NULL;
                }
            }
        }
    else
        {
       /* len_sub++; */
        counter = 0;
        while(counter < len_sub)
            {
            memcpy(&character, &mailadress[counter], 1);
            if(isalnum(character))
                {
                counter++;
                }
            else if(memcmp(&mailadress[counter], " ", 1) == 0)
                {
                if(counter)
                    {
                    len_sub = --counter;
                    }
                }
            else
                {
                counter++;
                }
            }
        rc = memicmp(subject_line, &mailadress[1], len_sub);
        }
    if(result || rc == 0)
        {
        free(mailadress);
        return(value);
        }

    else
        {
        free(mailadress);
        return(0);
        }
    }

char* search_for_key(char* body, int temp_len, char* key_ptr, int len_key)
    {
    int counter = 0;
    int len = 0;
    int rc = 0;
    int rest = 0;
    char *result = NULL;
    char *source = NULL;
    auto char *buffer = NULL;

    if(temp_len > 512)
        {
        temp_len = 512;
        }


    result = f_strstr(body, temp_len, key_ptr, len_key);
    if(result)
        {
        return(key_ptr);
        }

    len = temp_len;
    buffer = malloc(temp_len + 1);
    memcpy(buffer, body, temp_len);
    memset(&buffer[temp_len -1], '\0',1);
    rest = temp_len;

    while(counter < temp_len)
        {
        result = memchr(&buffer[counter], '\r', rest);
        if(!result)
            {
            result = memchr(&buffer[counter], '\n', rest);
            }
        if(result)
            {
            if(counter && memcmp(result - 1, "=", 1) == 0)
                {
                source = result;
                rest = &buffer[len] - source;
                memmove(result - 1, source, rest);
                counter = result - buffer;
                len -= 2;
                }
            else
                {
                source = result + 1;
                rest = &buffer[len] - source;
                memmove(result, source, rest);
                counter = result - buffer;
                len--;
                }
            }
        else
            {

            break;
            }
        }
    counter = 0;
    temp_len = len;
    rest = len;



    while(counter < temp_len)
        {
        result = memchr(&buffer[counter], '\n', rest);
        if(result)
            {
            if(counter && memcmp(result - 1, "=", 1) == 0)
                {
                source = result;
                rest = &buffer[len] - source;
                memmove(result - 1, source, rest);
                counter = result - buffer;
                len -= 2;
                }
            else
                {
                source = result + 1;
                rest = &buffer[len] - source;
                memmove(result, source, rest);
                counter = result - buffer;
                len--;
                }
            }
        else
            {
            break;
            }
        }

    counter = 0;
    temp_len = len;
    rest = len;

    while(counter < temp_len)
        {
        result = memchr(&buffer[counter], '<', rest);
        if(result)
            {
            rc = memicmp(result, "<br>", 4);
            rest = len - counter;
            if(! rc)
                {
                source = result + 1;
                rest = &buffer[len] - source;
                memmove(result, source, rest);
                counter = result - buffer;
                len -= 4;
                }
            }
        else
            {
            break;
            }
        }

    memset(&buffer[len], '\0', 1);
    result = f_strstr(buffer, temp_len, key_ptr, len_key);
    if(!result)
        {
        free(buffer);
        return(NULL);
        }
    free(buffer);
    return(key_ptr);
    }


char* f_strstr(char* string, int string_len, char* substring, int substring_len)
    {
    int character1 = 0;
    int rest = 0;
    int counter = 0;
    char* result = NULL;
    char* result1 = NULL;

    rest = string_len;

    memcpy(&character1, substring, 1);

    while(rest >= substring_len)
        {
        result = memchr(&string[counter], character1, rest);
        if(result)
            {
            if((memcmp(substring, result, substring_len)) == 0)
                {
                result1 = result;
                break;
                }
            rest = string_len - (result - string);
            rest--;
            counter = result - string;
            counter++;
            continue;
            }
        if(!result)
            {
            break;
            }
        }
    return(result1);
    }


int checkrelation(char* file_buffer_relationfile, int num_file_relationfile, char* from_mailadress, int len_from_mailadress, char* to_ptr)
    {
    char *adress_ptr = NULL;
    char *adress_end_ptr = NULL;
    int character = 0;
    char *end_of_line = NULL;
    char *end_ptr = NULL;
    char *new_line = NULL;
    int len_adress = 0;
    int len_to_ptr = 0;
    int rc = 0;
    char *result = NULL;
    int rest = 0;
    int strathegie = 0;
    char *strathegie_ptr = NULL;
    char temp_to_ptr[512] = {'\0'};



    len_to_ptr = f_strlen(to_ptr);
    memcpy(temp_to_ptr, "[", 1);
    strcat(temp_to_ptr, to_ptr);
    result = stristr(file_buffer_relationfile, num_file_relationfile, temp_to_ptr, len_to_ptr + 1);


    if(result)
        {
        strathegie_ptr = &result[len_to_ptr + 1];

        while(memcmp(strathegie_ptr, " ", 1) == 0)
            {
            strathegie_ptr++;
            }
        if((memcmp(strathegie_ptr, "NO]", 3)) == 0)
            {
            if(len_from_mailadress < 8)
                {
                return(-1);
                }
            strathegie = 1;
            }
        else if((memcmp(strathegie_ptr, "ALL]", 4)) == 0)
            {
            strathegie = 2;
            if(len_from_mailadress < 8)
                {
                return(0);
                }
            }
        else if((memcmp(strathegie_ptr, "]", 1)) == 0)
            {
            if(len_from_mailadress < 8)
                {
                return(0);
                }
            strathegie = 0;
            }

        rest = &file_buffer_relationfile[num_file_relationfile] - result;
        new_line = (memchr(result, '\r', rest));
        new_line += 2;
        end_ptr = (memchr(&result[1], '[', rest));

        if(end_ptr)
            {
            while(new_line <= end_ptr && rest > 0)
                {
                while(new_line <= end_ptr && rest > 0)
                    {
                    if(memcmp(new_line, " ", 1) == 0)
                        {
                        new_line++;
                        rest--;
                        }
                    else
                        {
                        break;
                        }
                    }

                adress_ptr = &new_line[1];
                while(memcmp(adress_ptr, " ", 1) == 0)
                    {
                    adress_ptr++;
                    }

                adress_end_ptr = adress_ptr;

                end_of_line = memchr(new_line, '\r', rest);

                while(adress_end_ptr < end_ptr)
                    {
                    memcpy(&character, adress_end_ptr, 1);
                    if(isprint(character) != 0)
                        {
                        adress_end_ptr++;
                        }
                    else
                        {
                        memset(adress_end_ptr, '\0', 1);
                        break;
                        }
                    }


                len_adress = f_strlen(adress_ptr);

                rc = memcmp(adress_ptr, from_mailadress, len_adress);
                if(!rc && strathegie == 0)
                    {
                    if(memcmp(new_line, "-", 1) == 0)
                        {
                        return(-1);
                        }
                    else if(memcmp(new_line, "+", 1) == 0)
                        {
                        return(1);
                        }
                    else
                        {
                        return(0);
                        }
                    }

                else if(rc == 0 && strathegie == 1)
                    {
                    if(memcmp(new_line, "-", 1) == 0)
                        {
                        return(-1);
                        }
                    else if(memcmp(new_line, "+", 1) == 0)
                        {
                        return(1);
                        }
                    else
                        {
                        return(0);
                        }
                    }
                else if(rc == 0 && strathegie == 2)
                    {
                    if(memcmp(new_line, "-", 1) == 0)
                        {
                        return(-1);
                        }
                    else if(memcmp(new_line, "+", 1) == 0)
                        {
                        return(1);
                        }
                    else
                        {
                        return(0);
                        }
                    }

                else
                    {
                    if(end_of_line)
                        {
                        new_line = end_of_line + 2;
                        }
                    else
                        {
                        break;
                        }
                    if(new_line && end_ptr + 2 > new_line)
                        {
                        new_line+= 2;
                        rest = end_ptr - new_line;
                        }
                    else
                        {
                        break;
                        }
                    }
                }
            if(strathegie == 0)
                {
                return(0);
                }
            if(strathegie == 1)
                {
                return(-1);
                }
            else
                {
                return(0);
                }
            }
        }
    else
        {
        return(0);
        }
    return(0);
    }

char* get_from_mailadress(char* begin_line)
    {
    int character = 0;
    int counter = 0;
    char *from_mailadress = NULL;
    char *temp_ptr = NULL;

    temp_ptr = strrchr(&begin_line[5], '@');
    if(temp_ptr)
        {
        while(temp_ptr > &begin_line[5])
            {
            memcpy(&character, &temp_ptr[counter], 1);
            if(memcmp(&temp_ptr[counter], "<", 1) == 0)
                {
                if(! from_mailadress)
                    {
                    from_mailadress = &temp_ptr[counter];
                    break;
                    }
                 }
            else
                {
                counter--;
                }
            }
        }
    return(from_mailadress);
    }

int check_user_logic(char* buffer, int buffer_len, char* adress, int size)
    {
    int counter = 0;
    char *domain_adress = NULL;
    int go_further = 0;
    int len = 0;
    char *rc_ptr = NULL;
    int rest = 0;

    rest = buffer_len;
    domain_adress = memchr(adress, '@', size);
    domain_adress++;

    while(memcmp(&buffer[counter], "[/", 2) != 0)
        {
        len = f_strlen(&buffer[counter]);

        if(memicmp(domain_adress, &buffer[counter], len) == 0)
            {
            go_further = 1;
            break;
            }
        else
            {
            counter = counter + len + 1;
            rest = buffer_len - counter;
            }
        }

    if(! go_further)
        {
        return(0);
        }

    rc_ptr = stristr(buffer, buffer_len, adress, size);
    if(rc_ptr)
        {
        return(1);
        }
    else
        {
        return(-1);
        }
    }


int cut_out_major_list_lines(long begin_cut_out, int argc, char *argv1, char *argv2, char *log_path_error, char *file_buffer_messagefile, int num_file_messagefile, char *body)
    {
    FILE *stream = NULL;
    int file_handle_messagefile = 0;
    int new_size_messagefile  = 0;
    if(begin_cut_out)
        {
         if(argc == 3)
             {
             file_handle_messagefile = open(argv2, O_RDWR | O_BINARY);             /*Datei zum Lesen îffnen*/

             if(file_handle_messagefile == -1)                                              /*Fehler */
                 {
                 if(errortracking)
                     {
                     stream = fopen(log_path_error,"a");
                     fprintf(stream, "%s open_message_file %i \n", asctime(newtime), errno);
                     fclose(stream);
                     close(file_handle_messagefile);                                            /* Datei Schliessen*/
                     exit(0);
                     }
                 }
             }
         else
             {
             file_handle_messagefile = open(argv1, O_RDWR | O_BINARY);             /*Datei zum Lesen îffnen*/
             if(file_handle_messagefile == -1)                                              /*Fehler */
                 {
                 if(errortracking)
                     {
                     stream = fopen(log_path_error,"a");
                     fprintf(stream, "%s open_message_file %i \n", asctime(newtime), errno);
                     fclose(stream);
                     close(file_handle_messagefile);                                            /* Datei Schliessen*/
                     exit(0);
                     }
                 }

             }
         lseek(file_handle_messagefile, begin_cut_out, SEEK_SET);
         write(file_handle_messagefile, "\r\n" , 2);
         write(file_handle_messagefile, body , num_file_messagefile - (&file_buffer_messagefile[num_file_messagefile] - body));
         new_size_messagefile = tell(file_handle_messagefile);
         _chsize(file_handle_messagefile, new_size_messagefile);
         close(file_handle_messagefile);
        }
    return(new_size_messagefile + 2);
    }
