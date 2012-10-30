    while (1) {
      if(ioctl(0,FIONREAD,&nlen) !=0) perror ("ioctl ??"); 
          for (ii=0;ii<nlen;ii++) { ch = getc(stdin) & 0x7f;
				   write(MeToReduce[1],&ch,1); }
      if(ioctl(ReduceToMe[0],FIONREAD,&nlen) !=0) perror ("ioctl to me??");
	  if (nlen > 0)
               {if ((plen = read(ReduceToMe[0], reduceOutputBuffer,
                       20480)) < 0) { printf ("Is nix da %d \n",plen);}
               else { for (ii=0;ii<nlen;ii++)
			 {putc(reduceOutputBuffer[ii],stdout);}
			fflush(stdout);} }
            else { /*printf ("Is NIX da %d \n",nlen); */
			sleep (1);};

              }
      ;
