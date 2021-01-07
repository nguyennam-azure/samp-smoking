#if defined _inc_main_cigar
    #undef _inc_main_cigar
#endif

#if defined _main_cigar_included
    #endinput
#endif
#define _main_cigar_included

#include "config-cigar"

CMD:usecigar(playerid, params[])
{
    new choice[10];

    if(sscanf(params, "s[10]", choice))
    {
        SendClientMessage(playerid, COLOR_FADE1, "/smokecigar [position]");
        SendClientMessage(playerid, COLOR_FADE1, "Position: mouth, righthand, lefthand");
        return 1;
    } 

    if(Cigar_GetTimes(playerid) > 0) return SendClientMessage(playerid, COLOR_FADE1, "Ban dang nham nhi dieu thuoc, khong hut them duoc!");

    if(!strcmp(params, "mouth", true))
    {
        Cigar_Create(playerid, 0);
    }
    else if(!strcmp(params, "righthand", true))
    {
        Cigar_Create(playerid, 1);
    }
    else if(!strcmp(params, "lefthand", true))
    {
        Cigar_Create(playerid, 2);
    }
    else return SendClientMessage(playerid, COLOR_FADE1, "Khong co su lua chon nay!");

    Streamer_Update(playerid);
    return 1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{  
    if(newkeys & KEY_FIRE && Cigar_GetTimes(playerid) > 0)
    {
        SetPlayerSpecialAction(playerid, SPECIAL_ACTION_SMOKE_CIGGY);
        if(--pCigar[playerid][cigarTimes] == 0)
        {
            Cigar_Remove(playerid);
        }
    }
    return 1;
}