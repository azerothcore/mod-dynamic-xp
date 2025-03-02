/*
Credits
Script reworked by Micrah/Milestorme and Poszer (Poszer is the Best)
Module Created by Micrah/Milestorme
Original Script from AshmaneCore https://github.com/conan513 Single Player Project
*/

#include "Chat.h"
#include "Configuration/Config.h"
#include "Player.h"
#include "ScriptMgr.h"

class spp_dynamic_xp_rate : public PlayerScript
{
public:
    spp_dynamic_xp_rate() : PlayerScript("spp_dynamic_xp_rate", {
        PLAYERHOOK_ON_LOGIN,
        PLAYERHOOK_ON_GIVE_EXP
    }) { };

    void OnPlayerLogin(Player* player) override
    {
        if (sConfigMgr->GetOption<bool>("Dynamic.XP.Rate.Announce", true))
            ChatHandler(player->GetSession()).SendSysMessage("This server is running the |cff4CFF00Level Dynamic XP |rmodule.");
    }

    void OnPlayerGiveXP(Player* player, uint32& amount, Unit* /*victim*/, uint8 /*xpSource*/) override
    {
        if (sConfigMgr->GetOption<bool>("Dynamic.XP.Rate", true))
        {
            if (player->GetLevel() <= 9)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.1-9", 1);
            else if (player->GetLevel() <= 19)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.10-19", 2);
            else if (player->GetLevel() <= 29)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.20-29", 3);
            else if (player->GetLevel() <= 39)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.30-39", 4);
            else if (player->GetLevel() <= 49)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.40-49", 5);
            else if (player->GetLevel() <= 59)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.50-59", 6);
            else if (player->GetLevel() <= 69)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.60-69", 7);
            else if (player->GetLevel() <= 79)
                amount *= sConfigMgr->GetOption<uint32>("Dynamic.XP.Rate.70-79", 8);
        }
    }
};

void AddSC_dynamic_xp_rate()
{
    new spp_dynamic_xp_rate();
}
