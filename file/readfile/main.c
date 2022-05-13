#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NETWORK_CONFIG "network.config"
#define NETWORK_IPADDR "IPADDR"
#define NETWORK_GATEWAY "GATEWAY"
#define NETWORK_NETMASK "NETMASK"

#define CONFIG_LINE_BUFFER_SIZE 128
#define MAX_CONFIG_VARIABLE_LEN 20

typedef struct network_config
{
    char ipaddr[20];
    char gateway[20];
    char netmask[20];
}network_config_t;

int read_network_config(char* filename, network_config_t* config)
{
    FILE *fp;
    char line_buffer[CONFIG_LINE_BUFFER_SIZE];

    if ((fp = fopen(filename, "r")) == NULL)
    {
        fprintf(stderr, "Failed to open config file %s", filename);
        return -1;
    }

    while (!feof(fp))
    {
        fgets(line_buffer, CONFIG_LINE_BUFFER_SIZE, fp);

        int len = strlen(line_buffer);
        if (line_buffer[0] == '#' || line_buffer[0] == '\n')
        {
            continue;
        }

        // trim
        char trim_buffer[CONFIG_LINE_BUFFER_SIZE] = {0};
        char * p_line_buf = line_buffer;
        char * p_trim_buf = trim_buffer;

        while (*p_line_buf != '\0')
        {
            if(*p_line_buf == '\n')
            {
                break;
            }

            if(!isspace(*p_line_buf))
            {
                *p_trim_buf = *p_line_buf;
                p_trim_buf ++;
            }
            p_line_buf ++;
        }
        
        char *pos = strchr(trim_buffer, '=');
        if (pos == NULL)
        {
            continue;
        }

        int offset = 1;
        if (trim_buffer[len - 1] == '\n')
        {
            offset = 2;
        }

        char key[64] = {0};
        char val[64] = {0};
        strncpy(key, trim_buffer, pos - trim_buffer);
        strncpy(val, pos + 1, trim_buffer + len - offset - pos);

        if(strcmp(key, NETWORK_IPADDR) == 0)
        {
            memcpy(config->ipaddr, val, sizeof(config->ipaddr));
        }
        else if(strcmp(key, NETWORK_GATEWAY) == 0)
        {
            memcpy(config->gateway, val, sizeof(config->gateway));
        }
        else if(strcmp(key, NETWORK_NETMASK) == 0)
        {
            memcpy(config->netmask, val, sizeof(config->netmask));
        }
    }

    fclose(fp);
    return 0;
}

int write_network_config(char* filename, network_config_t* config)
{
    // remove origin file
    remove(filename);

    // write a new file
    FILE *fp;

    if ((fp = fopen(filename, "w")) == NULL)
    {
        fprintf(stderr, "Failed to open config file %s", filename);
        return -1;
    }

    fprintf(fp, "IPADDR=%s", config->ipaddr);
    fprintf(fp, "GATEWAY=%s", config->gateway);
    fprintf(fp, "NETMASK=%s", config->netmask);

    fclose(fp);
    return 0;
}

int write_network_config_ipaddr(char* filename, const char* ipaddr)
{
    network_config_t new_config;
    

}

int main()
{
    network_config_t config;
	read_network_config(NETWORK_CONFIG, &config);

    printf("IPADDR: %s.\n", config.ipaddr);
    printf("GATEWAY: %s.\n", config.gateway);
    printf("NETMASK: %s.\n", config.netmask);


	return 0;
}