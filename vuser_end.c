vuser_end()
{
	tName = "08.Log_Out";
	lr_start_transaction(tName);
	
	status = web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	end_transaction(tName, status);
	lr_think_time(4);

	return 0;
}
