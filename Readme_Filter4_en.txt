First at all: Sorry for my bad english.
Filter_4.exe  0.42 is a Filtersoftware especial written for the Weasel mailserver.



Improvements:
Runtime measurements is now in miliseconds.




Filter_4 works on the Step4 when Weasel gets new mail.
Filter_4 is a badword filter.


Features
========

-Filtering for a binary match
-Filtering for any match
-Filtering for a word wich begins with
-Filtering for a word and not only a part
-Filtering for a word beginning in Uppercase
-Filtering for a word in Uppercase
-Filtering for any match in uppercase
-Filtering for a Emailadress from the topleveldomain
-Filtering for a weblink from the topleveldomain
-Filtering for a direct IP-Link
-decodes base64 coded mails bevor it scans the Email.


Lacks
=====
It does not support widechars or UTF-8
It does not support messages wich are encoded other then base 64
It does not support messages, wich are zipped


Files:
======
The file "filter4.ini" is a textfile and will recreated if not found. It will be created at the first run.
The file "adress" for all special emailadresses like friends or buissnespartners wich should not start at a initial value of 0.
The file "subject" for all bad words wich should not be in the subjectline.
The file "body" for all bad words wich shoud not be in the body.
The file "from_name": In this file we list all sendernames as they are used from spammers like: Viagra, Blue Pils ....
*** The file "relation": Every acount can have a relationlist with names of sender who are rejected, are taken or filterd.


The INI file
============

It uses a Text-INI-file to store hes values.
The inifile has to bee in the Weaseldirectory or in the same directory as the filter4.exe is.
If the inifile is not bee found Filter4.exe will wright a new and it fills it with default values.
This file will bee searched first in the same directory as the filter4.exe is. Afterwards in the weaseldirectory and if not found it creates a new in the exe directory.


whitelist=0
------------
reserved for future use


blacklist=0
-----------
reserved for future use


blacklist_temp=0
----------------
reserved for future use


returnpath=0
------------
reserved for future use


recieved=0
----------
reserved for future use


From_name=0
-----------
Set this to 1 if you like to scan for the "real name"
Hold it short and only set names of spammers in it. Don't use it for friends. For friends use the adressfile and set the Emailadress because it is more unike.


From_address=1
---------------
Filters in the Emailaddress corresponding to the file "address"
You may set a negativ value for friends. So firends can send even mail that is dedectet as "Spam"
If you set this value to 0 there will no search for Emailadresses.


to_name=0
---------
reserved for future use


reply_to=0
----------
reserved for future use


to_adress=0
-----------
reserved for future use


priority=0
----------
reserved for future use


content_type=1
--------------
Activates the decoding for base64 encoded Mails with the declaration Content-Type: base64.
To deactivate this feature set the value to 0.


content_transfer_encoding=1
---------------------------
Activates the decoding for base64 encoded Mails.
content_transfer_encoding= base64 is probably the wrong declaration, but used by some spammers.
To deactivate this feature set the value to 0.


message_id=0
------------
reserved for future use


mime_version=0
--------------
reserved for future use


Subject=1
---------
Filters The Subjectline wich has every Email coresponding to the File "subject"


Body_Scan=1
-----------
Filters the Emailbody wich has every Email coresponding to the File "body"


Body_Scan_Size=4
----------------
Most Spam is written in the very first kB. So it does not makes much sense to scan the hole massage.
Scanning the hole message can take hours, if you get a mail about 40 MB in size.
If you specify a 0 the hole message will be scanned.
The number tells the size in KB to be scanned.
A good scansize is between 4 and 8 as i have detect, but depeends on your own preferences.


Body_Scan_Multipart=1
---------------------
Scan especialy if it is a message in Multipart. Often Spamers writes that it is a multipartmessage, but very often one of the parts is empty.


Mailbombing=0
-------------
Some spammers do send the same spam over and over. I plan to make a tracking if this and take controll such servers
already at step 0. Right now it does not work.


Bombing_Amount=5
----------------
The amount of Spam from the same Server
You may alter the Value at your preferences


Bombing_time=15
---------------
Observationtime from the same server
You may alter the Value at your preferences


Bann_Time=24
------------
If the server sends as configured in 15 minutes 5 Spam it will be banned for 24 hours.
A 0 will take care of it for ever, wich i not recomend.
You may alter the Value at your preferences


Trigger_Value=99
----------------
If the value is higher then the Triggervalue, the mail is rejected as "Spam"
You may alter the Triggervalue at your preferences


Empty_Subject=20
----------------
If The subjectline is empty the Initia  lvalue raises 20.
You may alter the Value at your preferences.
Some Spamer try to bypass Spammfilter this way, but it could bee a friend of you, so take it with care.


Empty_body=50
-------------
If the Body is empty the Value raises 50.
You may alter the Value at your preferences.
Some spamer try on this way to dedect wether your Email-adress exist or not.
But can also be a mistake bi a friend.


Minimum_body_size=50
--------------------
A body needs to have a certain size, since Spammers sends empty Emails just to see wheter it is a valid adress.
The value "50" is the size in Bytes the body must have. If the body is smaler, it will be treaten like a empty body.
The value will raise of the value you have given on the line "Empty_body="
You may alter the Value at your preferences. It could be spam, but also a very short message of a friend.



Substitud=0
-----------
This is a planned feature. It searches for numbers instead of letter. Like w4tch in stead of watch. Or V1rgin islands instead of Virgin islands.


Stop=1
-------
Tells the Programm to stop scanning if the Triggervalue is exceded.
Put 0 to tell the programm:"Scan just to the end of the Mail or until your reach the "Body_scan_size".


Log=1
------
Puts some Logging output. At least at the beginning it makes sense.
Put a 0 for do not make loggin or any other value for do logging


IP_link=100
-----------
It rises the Value if a direct IP-Link is dedected. Such things like http://1.1.1.1/home or any other IP-Adress.
You may alter the Value at your preferences


Log_directory=
--------------
If you like another Logdirectory then the actual directory.


Log_errors =1
-------------
Filter_4 writes Errors in a separate File if it has for example not enough memory. Might bee helpfull from time to time.
Put a 0 for do not make loggin or any other value for do logging.
If a  exist in one of the lines of the files: "address, subject or body" The errorline will be noticed in the file:"filter_4_error.log"
Even when you have set Log_error=0
Right now it needs some developement.


copy_message=0
--------------
Filter_4 makes a copy from the files Namefile and Messagefile, wich sends Weasel to Filter_4.
If debug is set, copy_message will be ignored.
This will be on every mail you get. This makes only sense if you doo some debugging.


debug=0
-------
Filter_4 makes a copy from the files namefile and messagefile and renames it to namefile1 and messagefile1.
Filter_4 will not do anything with this two files. You have them to delete manually.
This makes only sense if you doo some debugging. It stores the mail that caused the crash.


refuse_self_adressing=0
-----------------------
When the senderadress and the recipientadres are the same the mail will be refused.
This entry is valid for all emailadresses !!


address_file=
-------------
You can put in the path to the adressfile. The path must bee complet INCLUSIVE the filename !!!
On the other hand the name of the file can be chosen as you like.
If there is no file entered filter4.exe searches first in the same directory as filter4 is, in second place in the Weaseldirectory.



Body_file=
----------
You can put in the path to the bodyfile. The path must bee complet INCLUSIVE the filename !!!
On the other hand the name of the file can be chosen as you like.
If there is no file entered filter4.exe searches first in the same directory as filter4 is, in second place in the Weaseldirectory.


Subject_file=
-------------
You can put in the path to the subjectfile. The path must bee complet INCLUSIVE the filename !!!
On the other hand the name of the file can be chosen as you like.
If there is no file entered filter4.exe searches first in the same directory as filter4 is, in second place in the Weaseldirectory.


fromname_file=
--------------
You can put in the path to the from_namefile. The path must bee complet INCLUSIVE the filename !!!
On the other hand the name of the file can be chosen as you like.
If there is no file entered filter4.exe searches first in the same directory as filter4 is, in second place in the Weaseldirectory.


log_runtime=0
-------------
Log_runtime=1 will tell you how long it took to filter a message. The result is rounded to a whole seconds.
Normaly this is not important. But when you scan the whole messages (Body_Scan_Size=0 and Stop =0) it will take from a half minute up too several minutes to scan a mail
wich has a size of 12MB.


log_all_recipients=0
--------------------
***If you have more then one recipient, it makes for every recipient one adress in the logfile. To activate this option you have to turn loging on
and set the value log_all_recipients= from 0 to 1
These logoutput is printed BEVOR the function check_relation. if log_after_relations = 1 is activated too the logoutput is doubled!!



log_after_relations=0
---------------------
This logoutput is createt after the function check_relation.


max_number_of_recipients=0
--------------------------
Limits the numbers of recipients. to don't have a limitation let the valu at 0.


check_relations=0
-----------------
Test wether the sender and the recipient have a relation in the ile relation. This can be thet the mail will be
- denied,
- acepted, altough in case that it is "Spam",
- or aceptet, but filterd


relation_file=
--------------
enter the path to the relation file. The path must be complet INCLUSIVE the filename !!!!!
But you may give a name you like. there is no limitaion.
If there is no filename it looks first in the filter4.exe folder and then after in the Weaselfolder.


remove_list_lines=0
-------------------
is a experimantal feature wich deletes the Listentris from mailinglists in the Header.
It should only be used in cases of emergency.



The Files
__________

All files have to have one entry each line nand not two ore more. It won't work!
There are at the moment three Files wich are important for Scanning:
-   address     wich contains the Adresses of Firends and or spammers
-   subject     wich contains the Bad words for wich Filter_4.exe has to scan
-   body        wich contains the bad words for wich Filter_4.exe has to scan
-   from_name   wich contains bad sender names for wich Filter_4.exe has to scan.


Notes to the INI-file
______________________

Filter_4.exe will write a new INI-File if it cannot find the file. It will work with defaul values.
Filter_4 searches the file first in the Homedirectory of the callerprogramm. This is usually the Weaseldirectory.
After this it loocks in the directory were Filter_4.exe is.
If you do a update: rename the INIfile befor you make the Update.



Syntax
======
Althoug it is a scanner for bad words, it can scan in different ways:
Each line begins with the value that will be added to the mail and if the value in total is higher as the Triggervalue the Mail will be rejected as Spam.

Example:
100: *badword

direct behind the value for the bad word you must set a doplepoint.
It makes no difference, whether you make some spaces to make it easier to read, or not behind the doublepoint
100:*badword   is the same as
100:    *  badword

At the end of the word you don't have to set some "*" or anything else. Blanks behind the badword will be ignored.

Normaly Filter_4.exe turns the "badword" in lowercase searches for it und afterwards it turns it to UPPERCASE and searches for it.
it does not makes any difference, how you type the badword.

house and HOUSE will be the same.


Syntax in advanced
------------------

*   search for any match in lovercase or in uppercase.
    100: * table    finds table, but also TABLE, DOWNTABLE, downtabel and tabledance so as TABLEDANCE tableDANCE

U   search for any match in Uppercase.
    100: U table will find TABLE, downTABLE and TABLEDANCE but not table, tabledance

b   The word must beginn with
    100: b table finds table, tabledance, TABLEDANCE but not downtable

B   The word must beginn with and must be Uppercase
    100: B table finds TABLE, TABLEdance but noch tabeldance or downTABLE.

=   This will search for a binary match
    100: = TaBlE will find only TaBlE It does not makes any differens if it is a whole word, begins with or it is in any verylong string

w   This will search for a word no matter if lower or uppercase
    100: w table will find tabel and TABLE, but not downtable, tables and also not TABLEDANCE...

W   This will search for a word and in Uppercase
    100: W table will find only TABLE

!   This will search for a domain
    100: ! spam.com will search on any Domain ....spam.com. It ignores subdomains!!!!!
    You can also just write the topleveldomain with or without the point befor it.
    100: ! .cc is the same as 100:!cc

@   This will search for a emailadress from the topleveldomain.
    100: @ spam.com will search for any emailadress to @....spam.org. It ignores subdomains!
    Anything like ...@no.spam.com will be rejected too.



Syntax in the Adresfile
-----------------------
Very first has to bee a number, wich should not bee -1 because this would indicate a error. Right after this number must be a doublepoint.
 after this you must have a (! @ or any other letter)
followed by a emailadres, a domain and if requested a option /NL /KEY /WKEY


Because -1 indicates a Error it is not allouwed to use -1.

.......
-200: @os2force.ch              @  This sets all seders of this domain to a startvalue of  -200
                                Important: it makes differences for Subdomains!!

-200: !os2force.ch              ! This will set all sender of this domain and all senders of all his subdomains to a startupvalue of -200

-10000:*fritz@os2force.ch       This puts fritz@os2force.ch to -10000  Instead of a * you can put any ohter one byte letter.
                                In mind that there are probably some Updates you should use * .


-1000:*no_loop@domain.ch /NL    The option /NL does not allows a loop for this sender. He cannot send emails to his own emailadres.
                                This can be needed by a mailinglist to prevent a endless loop.


-1000:*loop@domain.ch /KEY:"Key Phrase"
                                The option /KEY: makes, that in the first 512 bytes of the body will besearched for a Keywor oder Key-Sentence.
                                This way it is possible to bypass the /NL option. If the Key isfound a loop is allowed and the start value is set to -1000.
                                UTF-8 can make problems with theyr linebreaks.


0:*keine_filterung@domain.com /WKEY:"Key Prase"
                                /WKEY significants Whitekey and deactivates the /NL option plus it makes no filtering when the Key can be found in the
                                first 512 bytes of the body. There is still the linebreakproblem on UTF-8 linebraks.


Only one emailadress for each line


The Minus values are Friends. If you already put a positiv value at the entry, this sender will already start with a certain value and it will be earlyer rejected.
Right now i miss a "way to stopp filtering" when the sending emailaddress is a friend.



The Subject or body File Example:
=================================
.........


50:W   BBC              Will scan for the Word in uppercase "BBC"
100:   U    BIG!        Will scan for uppercase BIG! the "!" belongs also to the searched string
100:! cc                will search for anything that is http://......cc
100:U hour              will search for HUOR in uppercase
100:b sex               will search for a beginning word with sex. Will also match Sextant and sexiest but not Sussex
100:B Gratis            Will search for a beginning word for GRATIS Gratis will not match!
50:@ mail.com           will search for a mailaddres wich ends with mail.com
20:=Gratis              Will match only Gratis. Not GRATIS or gratis
20:*watches             will search for lover or uppercase watches



The relatiofile
================
there are three stratehgis with thre different signals:


NO:
---
All emaisl are refused exept, thoes ich begin with a + or a * at the beginning of the line


ALL:
----
All emails are welcome exept thoes beginning with a - or a * at the line


If there is nothing behind the Emailadress:
-------------------------------------------
All mails are filterd exept thos with a - or a +


Vorzeichen:
-----------

-fritz@os2force.ch means: This email will always be rejectet.
+fritz@os2force.ch means: This email is allways welcome without filtering !!
*fritz@os2force.ch means: This mail will be filterd and if it is no Spam it is welcome.



The File begins with a Systemline, wich is at the moment not needed but you never know


[$sys]                               <- The beginning of the system entry
 Adminkonop=Admin@irgendetwas        <- for a later use
 domains=4
some internal stuff                  <- for a later use
[/sys]                               <- End of the system entry


[OS2Force.ch]                        <- Begin of the domain, this is only for bether overview

[daniela@os2force.ch NO]             <- Begin of the user Daniela. NO means that all mails will be rejected exept from this senders
+sender1@xy.xx                       <- Mail from this sender is allways welcome without filtering!
+professor@university.com            <- Mail from this sender is allways welcome without filtering!
*Some.other.user@no.idea.com         <- This sender can send mail but it will be filterd
[/daniela]                           <- End of the entry of Daniela. This entry is a MUST

[doris@os2force.ch ALL]              <- New user. It gets all mail exept
-ruth@xy.xx                          <- This sender cannot send mail
*sender1@xy.xx                       <- This sender can send mail but it will be filterd
+New_boyfriend@zz.xx                 <- Mail from this sender is allways welcome without filtering!
-Ex_lover@another.domain.com         <- This sender cannot send mail
-staker@somewere.com                 <- This sender cannot send mail
[/doris]                             <- End of the entry of Doris. This entry is a MUST

[Pablo@os2force.ch]                  <- This is the normal way of handling mails exept
-Ex-Girlfriend@zz.xx                 <- This sender cannot send mail
*peter@urugu.oo                      <- This sender can send mail but it will be filterd
*sender1@xy.xx                       <- This sender can send mail but it will be filterd
[/Pablo]                             <- End of the entry of Pablo. This entry is a MUST

[/Os2force.ch]

Remarks
========


Beause this programm is written by miself it could have some Bugs!
Althogh it runs now since some weeks stable on my place this will not mean, that it runs perfect on your PC!
Use it first in a test area or if you don't have be critical. And take in the first time a look at your system.
Let Weasel do logging to the Harddisk and look for any Sys entrys.
You write probably a notice to the Weasel mailing list, so other users are informed, if Filter_4 causes any systems to
break down.
If you have any ideas for improvement or dedect bugs, tell me.


Filter_4 does not in every place the same success but it tears spam down. At mi place
from 400 Spam,  to under 10  each day. It depens what new "improvement" spammers dedect and what you add to your
files.
On your Server it could bee bether, or worse, depending what you put all in your files.
