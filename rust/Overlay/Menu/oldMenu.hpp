#pragma once
#include "Overlay.hpp"
#include "../SDK/Imports.hpp"
#include "Settings.hpp"
#include "../imgui/customfont.h"
#include "../imgui/customgui.h"


void configSam()
{
    Settings::enableAimbot = TRUE;
    Settings::enableAimbotDistance = TRUE;
    // Settings::enableDroppedItem = TRUE;
    Settings::enableVisuals = TRUE;
    Settings::enableRCS = TRUE;
    //Settings::drawBox = TRUE;
    //Settings::drawWeapon = TRUE;
    Settings::drawName = TRUE;
    Settings::drawCrosshair = TRUE;
    Settings::adminFlag = TRUE;
    Settings::drawHealthBar = TRUE;
    Settings::thickBullettt = TRUE;
    Settings::nightSky = TRUE;
    Settings::SpeedHack = TRUE;

    Settings::SpeedHackKey = 0x43;
    Settings::SpeedHackSpeed = -1;
    Settings::aimbotDistance = 100;
    // Settings::boxDistance = 200;
    Settings::nameDistance = 200;
    //Settings::weaponDistance = 200;
   // Settings::enableDroppedItemDistance = 100;

    Settings::RCSpitch = -10;
    Settings::RCSyaw = -10;
    Settings::aimbotFov = 60;

    Settings::CrosshairLength = 7;
    Settings::CrosshairGap = 3;
    Settings::CrosshairThickness = 2;


    //Settings::drawColor_box[0] = 1; Settings::drawColor_box[1] = 0; Settings::drawColor_box[2] = 0; Settings::drawColor_box[3] = 1;
    Settings::drawColor_name[0] = 1; Settings::drawColor_name[1] = 0; Settings::drawColor_name[2] = 0; Settings::drawColor_name[3] = 1;
    //Settings::drawColor_weapon[0] = 1;Settings::drawColor_weapon[1] = 1;Settings::drawColor_weapon[2] = 1;Settings::drawColor_weapon[3] = 1;
    //Settings::DroppedItemCol[0] = 1;Settings::DroppedItemCol[1] = 0.943396;Settings::DroppedItemCol[2] = 0;Settings::DroppedItemCol[3] = 1;
    Settings::espColorMisc[0] = 0.867925; Settings::espColorMisc[1] = 0; Settings::espColorMisc[2] = 1; Settings::espColorMisc[3] = 1;

}



void AimbotTab()
{
   // ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 62);
   // ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 10);
   // ImGui::BeginChild("Aimbot", ImVec2(400, 400), true);
    ImGui::SetCursorPos({ 200, 100 });
    ImGui::BeginChild("Aimbot", ImVec2(580, 440));
    {
        ImGui::TextColored(ImColor(175, 0, 255, 255), ("Aimbot"));
        CustomGUI::Checkbox("Enable Aimbot", &Settings::enableAimbot);
        ImGui::Text("Aimbot Key"); ImGui::SameLine(); ImGui::Hotkey("##Aimbot Key", &Settings::aimbotKey, ImVec2(80, 15));

        ImGui::Spacing();
        ImGui::Checkbox("Enable Smoothing", &Settings::enableSmoothing);
        if (Settings::enableSmoothing)
        {
            CustomGUI::SliderFloat(safe_str("smooth"), &Settings::aimSmoothing, 1, 100, safe_str("%.2f"), 1);
        }
        ImGui::Spacing();
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 18);
        ImGui::Spacing();
        CustomGUI::SliderInt("Aimbot FOV", &Settings::aimbotFov, 0, 360, "%.1f");

        CustomGUI::Checkbox("Enable Distance", &Settings::enableAimbotDistance);
        CustomGUI::SliderInt("Aimbot Distance", &Settings::aimbotDistance, 0, 300, "%.1f");

        ImGui::PushItemWidth(ImGui::GetWindowWidth() - 340);
        ImGui::Spacing();
        const char* listbox_items[] = { "Head", "Chest", "Pevlis" };
        ImGui::ListBox("##Hitbox", &Settings::aimbotHitbox, listbox_items, IM_ARRAYSIZE(listbox_items));
        CustomGUI::Checkbox("ThickBullet", &Settings::thickBullettt);

        ImGui::PopItemWidth();

        ImGui::EndChild();
    }
}

void MiscTab()
{
    //ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 62);
    //ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 10);
    //ImGui::BeginChild("Misc", ImVec2(400, 400), true);
    ImGui::SetCursorPos({ 200, 100 });
    ImGui::BeginChild("Misc", ImVec2(580, 440));
    {
        ImGui::TextColored(ImColor(175, 0, 255, 255), ("Weapon Options"));
        CustomGUI::Checkbox(("Rapid Fire"), &Settings::rapidFire);
        if (Settings::rapidFire)
        {
            CustomGUI::SliderFloat(("Rapid Fire Value"), &Settings::rapidfirevalue, 0.01, 0.09, safe_str("%.2f"), 1);
        }
        CustomGUI::Checkbox(("Enable RCS"), &Settings::enableRCS);
        if (Settings::enableRCS)
        {
            CustomGUI::SliderInt(("RCS Percentage X"), &Settings::RCSyaw, 0, -50, "%.0f");
            CustomGUI::SliderInt(("RCS Percentage Y"), &Settings::RCSpitch, 0, -50, "%.0f");
        }
        CustomGUI::Checkbox(("No Spread"), &Settings::noSpread);
        CustomGUI::Checkbox(("Instant Compound"), &Settings::instantCompound);
        CustomGUI::Checkbox(("Instant Switch"), &Settings::fastSwitchWeapons);

        ImGui::Spacing();

        ImGui::TextColored(ImColor(175, 0, 255, 255), ("Player Options"));
        CustomGUI::Checkbox(("Spider Climb"), &Settings::spiderClimb);

        CustomGUI::Checkbox(("Fast Kill"), &Settings::fastKill);
        if (Settings::fastKill)
        {
            ImGui::SameLine();
            ImGui::Hotkey(("##On Key2"), &Settings::fastKillKey, ImVec2(80, 15));
        }

        CustomGUI::Checkbox(("admin flag"), &Settings::adminFlag);
        CustomGUI::Checkbox(("TOD Changer"), &Settings::night_mode);
        if (Settings::night_mode)
            ImGui::SliderFloat(("Time"), &Settings::time, 0, 24);

        CustomGUI::Checkbox("Sky Color", &Settings::skyColorBool);
        if (Settings::skyColorBool)
            ImGui::SliderFloat("color", &Settings::SkyColor, 0, 100);


        CustomGUI::Checkbox(("Long Hit"), &Settings::longhit);
        CustomGUI::Checkbox(("instant eoka"), &Settings::tapeoka);
        CustomGUI::Checkbox(("third person"), &Settings::thirdperson);
        CustomGUI::Checkbox(("Long Neck"), &Settings::shootInAir);
        if (Settings::shootInAir)
        {
            ImGui::SameLine();
            ImGui::Hotkey(("##On Key1"), &Settings::LongNeckKey, ImVec2(80, 15));
        }
        CustomGUI::Checkbox("High Jump", &Settings::SuperJump);
        if (Settings::SuperJump)
        {
            CustomGUI::SliderFloat("value", &Settings::GravitySlider, 10, 0, "%.0f", 1);
        }
        CustomGUI::Checkbox("Debug Camera Fix", &Settings::DebugFix);
        CustomGUI::Checkbox("Hold Items While Mounted", &Settings::ShootMounted);
        CustomGUI::Checkbox("Speed Hack", &Settings::SpeedHack);
        if (Settings::SpeedHack)
        {
            ImGui::Hotkey(("##On Key69"), &Settings::SpeedHackKey, ImVec2(80, 15));
            CustomGUI::SliderFloat("Speed", &Settings::SpeedHackSpeed, 10, -10, "%.0f", 1);
        }
        CustomGUI::Checkbox(("Bright Night"), &Settings::nightSky);
        CustomGUI::Checkbox(("Run Hit"), &Settings::runhit);
        CustomGUI::Checkbox(("Zoom"), &Settings::zoom);
        if (Settings::zoom)
        {
            ImGui::Hotkey(("##On Key4"), &Settings::zoomKey, ImVec2(80, 15));
        }
        CustomGUI::Checkbox("Player Swim", &Settings::waterLevel);
        CustomGUI::Checkbox("Infinate Jump", &Settings::infinateJump);
        if (Settings::infinateJump)
        {
            ImGui::Hotkey(("##On Key1"), &Settings::jumpKey, ImVec2(80, 15));

        }
        CustomGUI::Checkbox("FlyHack", &Settings::flyHackkk);
        if (Settings::flyHackkk)
        {
            ImGui::Hotkey("##Flyhack Key", &Settings::flyhackKey, ImVec2(80, 15));
            CustomGUI::SliderFloat(("speed"), &Settings::flyhackSpeed, 6, -5, "%.0f", 1);
        }

        ImGui::EndChild();
    }
}
const char* boxTypes[] = { ("Static Box"), ("Corner Box"), ("Filled Box") };
const char* oresItems[] = {
    "Stone Ore",
    "Metal Ore",
    "Sulfur Ore",
    "Stone Collectable",
    "Metal Collectable",
    "Sulfur Collectable",
    "Wood Collectable",
    "Hemp Fibers",
    "Stash",
    "Barrel",
    "Oil Barrel",
    "Elite Crate",
    "Military Crate",
    "Medical Crate",
    "Normal Crate",
    "Food Crate",
    "Tool Box",
    "Boat",
    "RHIB",
    "kayak",
    "Minicopter",
    "Bradley",
    "Corpse" };
void VisualTab()
{
   // ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 62);
   // ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 10);
   // ImGui::BeginChild("Visuals", ImVec2(400, 400), true);
    ImGui::SetCursorPos({ 200, 100 });
    ImGui::BeginChild("Visuals", ImVec2(580, 440));
    {
        CustomGUI::Checkbox("Enable Visuals", &Settings::enableVisuals);
        ImGui::Spacing();

        CustomGUI::Checkbox(("Player Box"), &Settings::drawBox); ImGui::ColorEdit4(("Box Color"), Settings::drawColor_box, ImGuiColorEditFlags_NoInputs);
        if (Settings::drawBox) {
            CustomGUI::Combo(("Box Type"), &Settings::typeBox, boxTypes, 3);
            CustomGUI::SliderInt(("Distance##Distance1"), &Settings::boxDistance, 100, 300, "%.1f");
        }

        CustomGUI::Checkbox(("Weapon ESP"), &Settings::drawWeapon); ImGui::ColorEdit4(("Weapon Color"), Settings::drawColor_weapon, ImGuiColorEditFlags_NoInputs);
        if (Settings::drawWeapon)
            CustomGUI::SliderInt(("Distance##Distance123798"), &Settings::weaponDistance, 100, 300, "%.1f");

        CustomGUI::Checkbox(("Skeleton"), &Settings::drawSkeleton); ImGui::ColorEdit4(("Skeleton Color"), Settings::drawColor_skeleton, ImGuiColorEditFlags_NoInputs);
        if (Settings::drawSkeleton)
            CustomGUI::SliderInt(("Distance##Distance3"), &Settings::skeletonDistance, 100, 300, "%.1f");


        CustomGUI::Checkbox(("Name"), &Settings::drawName); ImGui::ColorEdit4(("Name Color"), Settings::drawColor_name, ImGuiColorEditFlags_NoInputs);
        if (Settings::drawName)
            CustomGUI::SliderInt(("Distance##Distance4"), &Settings::nameDistance, 100, 300, "%.1f");

        CustomGUI::Checkbox(("Health Bar"), &Settings::drawHealthBar);
        if (Settings::drawHealthBar)
            CustomGUI::SliderInt(("Distance##Distance2"), &Settings::healthDistance, 100, 300, "%.1f");

        CustomGUI::Checkbox(("Dropped Items"), &Settings::enableDroppedItem); ImGui::ColorEdit4(("Item Color"), Settings::DroppedItemCol, ImGuiColorEditFlags_NoInputs);
        if (Settings::enableDroppedItem)
            CustomGUI::SliderInt(("Distance##Distance43234"), &Settings::enableDroppedItemDistance, 100, 300, "%.1f");

        CustomGUI::Checkbox(("Crosshair"), &Settings::drawCrosshair); ImGui::ColorEdit4(("Crosshair Color"), Settings::drawColor_crosshair, ImGuiColorEditFlags_NoInputs);
        if (Settings::drawCrosshair)
        {
            CustomGUI::Checkbox("while scoped", &Settings::crosshairScoped);
            CustomGUI::SliderInt("Length", &Settings::CrosshairLength, 1, 24, "%.1f");
            CustomGUI::SliderInt("Gap", &Settings::CrosshairGap, 0, 24, "%.1f");
            CustomGUI::SliderInt("Thickness", &Settings::CrosshairThickness, 1, 24, "%.1f");
        }

        CustomGUI::SliderInt(("Fov Changer"), &Settings::FovSlider, 75, 150, "%.1f");


        ImGui::TextColored(ImColor(175, 0, 255, 255), "ESP Object List");
        ImGui::ColorEdit4(("Color"), Settings::espColorMisc, ImGuiColorEditFlags_NoInputs);
        if (ImGui::ListBoxHeader("##ESP Object List"))
        {
            for (size_t i = 0; i < IM_ARRAYSIZE(Settings::selectedOres); i++) {
                ImGui::Selectable(oresItems[i], &Settings::selectedOres[i], ImGuiSelectableFlags_::ImGuiSelectableFlags_DontClosePopups);
            }
            ImGui::ListBoxFooter();
        }
        ImGui::EndChild();
    }
}

void SettingsTab()
{
    //ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 62);
    //ImGui::SetCursorPosY(ImGui::GetCursorPosY() - 10);
    //ImGui::BeginChild("Settings", ImVec2(580, 440), true); //350, 250
    ImGui::SetCursorPos({ 200, 100 });
    ImGui::BeginChild("Settings", ImVec2(580, 440));
    {
        if (ImGui::Button("EXIT CHEAT"))
            exit(-1);
        if (ImGui::Button("Load admin Config"))
            configSam();
        ImGui::EndChild();
    }
}
void __fastcall DrawMenu()
{
    ImGui::SetNextWindowSize(ImVec2(screenWidth + 15, screenHeight + 15));
    ImGui::SetNextWindowPos(ImVec2(-10, -10));
    ImGui::SetNextWindowBgAlpha(255.f);

    //ImGui::Begin(safe_str("Background"), (bool*)true, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoMove);
    //{
       // ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.120, 0.900, 0.933, .2f));
     //   ImGui::PopStyleColor();
      //  ImGui::End();
    //}

    //Window Size
    ImGui::SetNextWindowSize(ImVec2(800, 550));
    ImGui::SetNextWindowPos(ImVec2((1920 - 840) * .5, (1080 - 500) * .5), ImGuiCond_Once);

    ImGui::Begin(safe_str("main"), (bool*)true, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
    {
        ImGui::SetScrollY(0);

        ImVec2 p = ImGui::GetCursorScreenPos();
        ImColor barColors = ImColor(88, 0, 255, 255);

        /*		//Topbar
                ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImVec2(p.x, p.y + 32), ImVec2(p.x + ImGui::GetWindowWidth(), p.y + +30), ImColor(255, 34, 0, 255),
                    barColors, barColors, barColors);
                //Sidebar
                ImGui::GetWindowDrawList()->AddRectFilledMultiColor(ImVec2(p.x + 70, p.y + 32), ImVec2(p.x + 68, p.y + ImGui::GetWindowHeight()), ImColor(255, 34, 0, 255),
                    barColors, barColors, barColors);*/

       // ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.512f, 0.0f, 0.0f, 1.f));
       // ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(78 / 255.f, 78 / 255.f, 87 / 255.f, 1));
       // ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.117, 0.117, 0.152, 1));
       // ImGui::PushStyleVar(ImGuiStyleVar_ButtonTextAlign, ImVec2(0.5f, 0.5f));

        // FLAGS
        auto window_flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoScrollbar;

        // ATRIBUTES
        ImGui::SetNextWindowSize({ 800,550 });

        // STYLES
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 4);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarSize, 1);

        // COLORS
        ImGui::PushStyleColor(ImGuiCol_WindowBg, { 235 / 255.f,235 / 255.f,235 / 255.f,255 / 255.f });
        ImGui::PushStyleColor(ImGuiCol_Text, { 70 / 255.f,70 / 255.f,70 / 255.f,255.f / 255.f });
        ImGui::PushStyleColor(ImGuiCol_ScrollbarBg, { 35.f / 255.f,35.f / 255.f,35.f / 255.f,0 / 255.f });

        ImVec2 position;
        ImDrawList* draw;

        position = ImGui::GetWindowPos();
        draw = ImGui::GetWindowDrawList();

        draw->AddRectFilled(ImVec2{ position.x + 180,position.y + 50 }, ImVec2{ position.x + 800,position.y + 550 }, ImColor(229 / 255.f, 229 / 255.f, 231 / 255.f, 255 / 255.f), 4, ImDrawCornerFlags_BotRight);
        draw->AddLine(ImVec2{ position.x + 180,position.y }, ImVec2{ position.x + 180,position.y + 550 }, ImColor(120 / 255.f, 120 / 255.f, 120 / 255.f, 70.f / 255.f));
        draw->AddLine(ImVec2{ position.x,position.y + 50 }, ImVec2{ position.x + 800,position.y + 50 }, ImColor(120 / 255.f, 120 / 255.f, 120 / 255.f, 70.f / 255.f));


        draw->AddLine(ImVec2{ position.x + 200,position.y + 90 }, ImVec2{ position.x + 780,position.y + 90 }, ImColor(120 / 255.f, 120 / 255.f, 120 / 255.f, 100.f / 255.f));

        draw->AddText({ position.x + 20,position.y + 70 }, ImColor(70 / 255.f, 70 / 255.f, 70 / 255.f, 255.f / 255.f), "FEATURES");
        draw->AddText({ position.x + 20,position.y + 210 }, ImColor(70 / 255.f, 70 / 255.f, 70 / 255.f, 255.f / 255.f), "INFORMATION");

        ImGui::PushFont(CustomGUI::fonts::SFUIbold_bigger);
        draw->AddText({ position.x + 20,position.y + 50 / 2 - ImGui::CalcTextSize("vos.club").y / 2 }, ImColor(70 / 255.f, 70 / 255.f, 70 / 255.f, 255.f / 255.f), "vos.club");
        ImGui::PopFont();

        static int page = 0;
        static int subtab = 0;
        ImGui::PushFont(Overlay::fontMenu);
        ImGui::SetCursorPos({ 20, 90 });
        if (CustomGUI::Tab("Ragebot", "1", page == 0, { 140,25 }))
            page = 0;

        ImGui::SetCursorPos({ 20, 120 });
        if (CustomGUI::Tab("Visuals", "2", page == 1, { 140,25 }))
            page = 1;

        ImGui::SetCursorPos({ 20, 150 });
        if (CustomGUI::Tab("Misc", "3", page == 2, { 140,25 }))
            page = 2;

        ImGui::SetCursorPos({ 20, 180 });
        if (CustomGUI::Tab("Settings", "4", page == 3, { 140,25 }))
            page = 3;

        ImGui::SetCursorPos({ 20, 230 });
        if (CustomGUI::Tab("Dashboard", "a", page == 4, { 140,25 }))
            page = 4;

        if (page == 0)
        {
            ImGui::SetCursorPos({ 200, 66 });
            if (CustomGUI::SubTab("AIMBOT", subtab == 0, { 63,25 }))
                subtab = 0;
        }
        if (page == 1)
        {
            ImGui::SetCursorPos({ 200, 66 });
            if (CustomGUI::SubTab("ESP", subtab == 0, { 41,25 }))
                subtab = 0;

            ImGui::SetCursorPos({ 246, 66 });
            if (CustomGUI::SubTab("COLORS", subtab == 1, { 62,25 }))
                subtab = 1;
        }
        if (page == 2)
        {
            ImGui::SetCursorPos({ 200, 66 });
            if (CustomGUI::SubTab("Weapon Options", subtab == 0, { 41,25 }))
                subtab = 0;

            ImGui::SetCursorPos({ 246, 66 });
            if (CustomGUI::SubTab("Player Options", subtab == 1, { 62,25 }))
                subtab = 1;
        }


        ImGui::PopFont();

        ImGui::PopStyleColor();
        ImGui::PopStyleColor();
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();

        ImGui::SetCursorPosY(9);

        ImGui::Dummy(ImVec2(0, 25));
        ImGui::Dummy(ImVec2(0, 0)); ImGui::SameLine();
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(16, 16));

        ImGui::PushFont(Overlay::fontMenu);
        switch (page)
        {
        case 0:
            AimbotTab(); break;
        case 1:
            VisualTab(); break;
        case 2:
            MiscTab(); break;
        case 3:
            SettingsTab(); break;
        }
        ImGui::PopFont();
        ImGui::PopStyleVar();

        ImGui::SetCursorPosY(305);
        ImVec2 p2 = ImGui::GetCursorScreenPos();
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + 3);
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 650);
        //ImGui::Text(("Rust"));

        ImGui::End();
    }
}