#if defined _inc_config_cigar
    #undef _inc_config_cigar
#endif

#if defined _config_cigar_included
    #endinput
#endif
#define _config_cigar_included

enum CigarettesEnum
{
    cigarObject,
    cigarTimes
}

new 
    pCigar[MAX_PLAYERS][CigarettesEnum];

stock Cigar_Create(playerid, position)
{
    new Float:rx, Float:ry, Float:rz, Float:offsetx, Float:offsety, Float:offsetz;

    switch(position)
    {
        case 0:
        {
            offsetx = 0.0079;
            offsety = 0.1039;
            offsetz = 0.0000;
            rx = -176.9000;
            ry = 0.0000;
            rz = 0.0000;
        }
        case 1:
        {
            offsetx = 0.1020;
            offsety = 0.0000;
            offsetz = 0.0000;
            rx = 1.1999;
            ry = 0.0000;
            rz = 35.6999;
        }
        case 2:
        {
            offsetx = 0.1070;
            offsety = 0.0000;
            offsetz = 0.0000;
            rx = 0.0000;
            ry = 0.0000;
            rz = 33.3999;
        }
    }    

    pCigar[playerid][cigarObject] = CreateDynamicObject(19625, 0.0, 0.0, 0.0, 0.0, 0.0, 90.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), playerid);
    AttachDynamicObjectToPlayer(pCigar[playerid][cigarObject], playerid, offsetx, offsety, offsetz, rx, ry, rz);
    Cigar_SetTimes(playerid, 3);
    return 1;
}

stock Cigar_Remove(playerid)
{
    DestroyDynamicObject(pCigar[playerid][cigarObject]);
    return 1;
}

stock Cigar_SetTimes(playerid, times)
{
    return pCigar[playerid][cigarTimes] = times;
}

stock Cigar_GetTimes(playerid)
{
    return pCigar[playerid][cigarTimes];
}