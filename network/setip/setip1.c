#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <error.h>
#include <net/route.h>
 
int SetIfAddr(char *ifname, char *Ipaddr, char *mask,char *gateway)
{
    int fd;
    int rc;
    struct ifreq ifr;
    struct sockaddr_in *sin;
    struct rtentry  rt;
   
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    if(fd < 0)
    {
            perror("socket   error");    
            return -1;    
    }
    memset(&ifr,0,sizeof(ifr));
    strcpy(ifr.ifr_name,ifname);
    sin = (struct sockaddr_in*)&ifr.ifr_addr;    
    sin->sin_family = AF_INET;  
  
    //ipaddr
    if(inet_aton(Ipaddr,&(sin->sin_addr)) < 0)  
    {    
        perror("inet_aton   error");    
        return -2;    
    }   
   
    if(ioctl(fd,SIOCSIFADDR,&ifr) < 0)  
    {    
        perror("ioctl   SIOCSIFADDR   error");    
        return -3;    
    }

    //netmask
    if(inet_aton(mask,&(sin->sin_addr)) < 0)  
    {    
        perror("inet_pton   error");    
        return -4;    
    }   
    if(ioctl(fd, SIOCSIFNETMASK, &ifr) < 0)
    {
        perror("ioctl");
        return -5;
    }

    //gateway
    memset(&rt, 0, sizeof(struct rtentry));
    memset(sin, 0, sizeof(struct sockaddr_in));
    sin->sin_family = AF_INET;
    sin->sin_port = 0;
    if(inet_aton(gateway, &sin->sin_addr)<0)
    {
       printf ( "inet_aton error\n" );
    }
    memcpy ( &rt.rt_gateway, sin, sizeof(struct sockaddr_in));
    ((struct sockaddr_in *)&rt.rt_dst)->sin_family=AF_INET;
    ((struct sockaddr_in *)&rt.rt_genmask)->sin_family=AF_INET;
    rt.rt_flags = RTF_GATEWAY;
    if (ioctl(fd, SIOCADDRT, &rt)<0)
    {
        zError( "ioctl(SIOCADDRT) error in set_default_route\n");
        close(fd);
        return -1;
    }
    close(fd);
    return rc;
}



int usb_chann_setip(char *ip)
{
	struct ifreq temp;
	struct sockaddr_in *addr;
	int fd = 0;
	int ret =-1;
 
	strcpy(temp.ifr_name, "usb0");
 
 
	if((fd = socket(AF_INET, SOCK_STREAM, 0))<0){
		++usb_info.setip_socket_open_failed;
		return -1;
	}
 
	addr = (struct sockaddr_in *)&(temp.ifr_addr);
	addr->sin_family = AF_INET;
	addr->sin_addr.s_addr = inet_addr(ip);
	ret = ioctl(fd, SIOCSIFADDR, &temp);
	close(fd);
 
	if(ret < 0){
		++usb_info.setip_socket_ioctl_failed;
		return -1;
	}
 
	return 0;
}
 
char *usb_chann_getip(char *ip_buf)
{
	struct ifreq temp;
	struct sockaddr_in *myaddr;
	int fd = 0;
	int ret =-1;
 
	strcpy(temp.ifr_name, "usb0");
 
	if ((fd = socket(AF_INET, SOCK_STREAM, 0))<0){
		++usb_info.getip_socket_open_failed;
		return NULL;
	}
 
	ret = ioctl(fd, SIOCGIFADDR, &temp);
	close(fd);
 
	if (ret < 0){
		++usb_info.getip_socket_ioctl_failed;
		return NULL;
	}
 
	myaddr = (struct sockaddr_in *)&(temp.ifr_addr);
	strcpy(ip_buf, inet_ntoa(myaddr->sin_addr));
 
	return ip_buf;
}
