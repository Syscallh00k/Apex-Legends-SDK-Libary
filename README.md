# Apex-Legends-SDK-Libary
Full customizable 4 internal / external 

Image: 
![alt text]([http://url/to/img.png](https://media.discordapp.net/attachments/1232722469023125594/1235976120919392256/image.png?ex=66423176&is=6640dff6&hm=a814cd13c0dec02b88257d577581ff0c66ae4784e07c18df4e159b29187759d8&=&format=webp&quality=lossless&width=832&height=468))
Example : 

```ruby
for (int i = 0; i <= 255; i++)
{
	SDK::Entity* Entity = Read<SDK::Entity*>(sdk.R5Apex + 0x1dd45f8 + ((static_cast<unsigned long long>(i) + 1) << 5));

	Entity->Update();

	if (!Entity->IsPlayer || !Entity->Is_Alive || Entity->IsLocalPlayer) continue;

	if (Entity->Feet_Position.Empty()) continue;

	ImGui::GetBackgroundDrawList()->AddText(ImVec2(Entity->Feet_Position.x, Entity->Feet_Position.y), ImColor(255, 255, 255, 255), "Entity");
} 

```


