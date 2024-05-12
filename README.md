# Apex-Legends-SDK-Libary
Full customizable 4 internal / external 

Example : 
```for (int i = 0; i <= 255; i++)
{
	SDK::Entity* Entity = Read<SDK::Entity*>(sdk.R5Apex + 0x1dd45f8 + ((static_cast<unsigned long long>(i) + 1) << 5));

	Entity->Update();

	if (!Entity->IsPlayer || !Entity->Is_Alive || Entity->IsLocalPlayer) continue;

	if (Entity->Feet_Position.Empty()) continue;

	ImGui::GetBackgroundDrawList()->AddText(ImVec2(Entity->Feet_Position.x, Entity->Feet_Position.y), ImColor(255, 255, 255, 255), "Entity");
} ```


