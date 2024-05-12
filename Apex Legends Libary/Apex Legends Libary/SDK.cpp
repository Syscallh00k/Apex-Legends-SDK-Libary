#include "SDK.hpp"


// Get
std::uint64_t SDK::Game::Get::getAddress() {
	uint64_t Address = ((uint64_t)this);
	if (!Address) return 0;
	else return Address;
}
//END

// SCRIPT

std::string SDK::Game::Script::GetName()
{
	if (!this->getAddress()) return "";
	for (int i = 0; i < 150; i++)
	{
		uintptr_t EntityList = Read<uintptr_t>(sdk.R5Apex + Offsets::Misc::EntityList);
		uintptr_t BaseEntity = Read<DWORD64>(EntityList);
		if (!BaseEntity)
			continue;
		uintptr_t ent = Read<uintptr_t>(EntityList + (i << 5));
		if (ent == NULL)
			continue;
		uintptr_t nameptr = Read<uintptr_t>(sdk.R5Apex + Offsets::Misc::NameList + (i - 1) * 0x10);
		if (!nameptr) continue;
		return ReadString(nameptr);

	}
	return "";
}
std::string SDK::Game::Script::getModelName()
{
	
	if (!this->getAddress()) return "";
	uintptr_t pMode_Name = Read<uintptr_t>(this->getAddress() + Offsets::C_BaseEntity::m_ModelName);
	if (!pMode_Name) return "";
	return ReadString(pMode_Name);
}
std::string SDK::Game::Script::getSignifierName()
{
	if (!this->getAddress()) return "";
	uintptr_t sigAddr = Read<uintptr_t>(this->getAddress() + Offsets::DT_BaseEntity::m_iSignifierName);
	if (!sigAddr)
		return "";
	return ReadString(sigAddr);
}

//END

// WORLD TO SCREEN

Vector3 SDK::Game::WorldToScreen::W2S(Vector3 Position)
{
	std::uintptr_t render = Read<std::uintptr_t>(sdk.R5Apex + Offsets::Misc::ViewRender);
	if (!render)return { 0,0,0 };

	std::uintptr_t  Matrixa = Read<std::uintptr_t>(Offsets::Misc::ViewMatrix + render);
	if (!Matrixa)return { 0,0,0 };

	BaseMatrix Matrix = Read<BaseMatrix>(Matrixa);

	Vector3 out;
	float _x = Matrix.at[0] * Position.x + Matrix.at[1] * Position.y + Matrix.at[2] * Position.z + Matrix.at[3];
	float _y = Matrix.at[4] * Position.x + Matrix.at[5] * Position.y + Matrix.at[6] * Position.z + Matrix.at[7];
	out.z = Matrix.at[12] * Position.x + Matrix.at[13] * Position.y + Matrix.at[14] * Position.z + Matrix.at[15];

	if (out.z < 0.1f) return { 0,0,0 };

	_x *= 1.f / out.z;
	_y *= 1.f / out.z;

	out.x = sdk.DisplaySize.x * .5f;
	out.y = sdk.DisplaySize.y * .5f;

	out.x += 0.5f * _x * sdk.DisplaySize.x + 0.5f;
	out.y -= 0.5f * _y * sdk.DisplaySize.y + 0.5f;

	return out;
}

//END

//GLOW

void SDK::Glow::SetGlow(int GlowEnabled, int GlowThroughWall, int HighlightID)
{
	Write<int>(this->getAddress() + Offsets::Misc::OFF_GLOW_ENABLE, GlowEnabled);
	Write<int>(this->getAddress() + Offsets::Misc::OFF_GLOW_THROUGH_WALL, GlowThroughWall);
	Write<int>(this->getAddress() + Offsets::Misc::OFF_GLOW_FIX, 2);
}
void SDK::Glow::DisableGlow()
{
	Write<int>(this->getAddress() + Offsets::Misc::OFF_GLOW_ENABLE, 0);
	Write<int>(this->getAddress() + Offsets::Misc::OFF_GLOW_THROUGH_WALL, 0);
	Write<int>(this->getAddress() + Offsets::Misc::OFF_GLOW_FIX, 0);
}

//END


//ENTITY

void SDK::Entity::Update()
{
	this->IsPlayer = Get_IsPlayer();
	this->IsLocalPlayer = Get_IsLocalPlayer();
	this->Health = Current_Health();
	this->Shield = Get_Current_shield();
	this->Max_Shield = Get_Max_shield();
	this->Is_Alive = Get_Alive();
	this->Shield_Type = Get_shield_type();
	this->Feet_Position = this->W2S(Get_Position());
	this->Head_Position = this->W2S(GetBonePositionByHitBox(0));
	this->Distance = GetDistance();
	this->Height = Get_Height();
	this->Width = Get_Width();
}
void SDK::Entity::Set_Network_Flags(int Network_Flag) {
	Write<int>(this->getAddress() + Offsets::DT_BaseEntity::m_networkedFlags, Network_Flag);

}
void SDK::Entity::ignoreParentRotation(int Rotation) {
	Write<int>(this->getAddress() + Offsets::DT_BaseEntity::m_ignoreParentRotation, Rotation);

}
void SDK::Entity::Set_PassthroughThickness(int thickness) {
	Write<int>(this->getAddress() + Offsets::DT_BaseEntity::m_passThroughThickness,thickness);
}

float  SDK::Entity::GetDistance() {
	return this->Get_Position().distance(this->LocalPlayer()->Get_Position());
}
float SDK::Entity::Get_Height()
{
	return this->Head_Position.y - this->Feet_Position.y;
}
float SDK::Entity::Get_Width()
{
	return this->Height / 2;
}

int SDK::Entity::Current_Health()
{
	return Read<int>(this->getAddress() + Offsets::DT_Player::m_iHealth);
}
int SDK::Entity::Get_Current_shield()
{
	return Read<int>(this->getAddress() + Offsets::DT_BaseEntity::m_shieldHealth);

}
int SDK::Entity::Get_Max_shield()
{
	return Read<int>(this->getAddress() + Offsets::DT_BaseEntity::m_shieldHealthMax);

}
int SDK::Entity::Get_shield_type()
{
	return Read<int>(this->getAddress() + Offsets::DT_BaseEntity::m_Shield_type);

}
int SDK::Entity::Get_Network_Flags() {
	return Read<int>(this->getAddress() + Offsets::DT_BaseEntity::m_passThroughThickness);
}
int SDK::Entity::Get_TeamNum() {
	return Read<int>(this->getAddress() + Offsets::DT_BaseEntity::m_iTeamNum);
}

bool  SDK::Entity::Get_IsPlayer()
{
	if (this->getSignifierName() == "player")
		return true;
	else
		return false;
}
bool SDK::Entity::Get_IsLocalPlayer()
{
	if (this->LocalPlayer()->getAddress() == this->getAddress())
		return true;
	else
		return false;
}
bool SDK::Entity::Get_Alive()
{
	if (this->Health <= 0.1f)
		return false;
	else
		return true;
}

Vector3  SDK::Entity::Get_Position()
{

	Vector3 Pos = Read<Vector3>(this->getAddress() + Offsets::C_BaseEntity::m_vecAbsOrigin);
	if (Pos.Empty()) return { 0,0,0 };
	return Pos;
}
Vector3  SDK::Entity::getBonePos(int ID)
{
	Vector3 pos = this->Get_Position();
	if (pos.Empty()) return { 0,0,0 };
	uintptr_t bones = Read<uintptr_t>(this->getAddress() + Offsets::Misc::Bones); //PoopSets::demfuckingBone
	Vector3 bone = {};
	UINT32 boneloc = (ID * 0x30);
	bone_t bo = {};
	bo = Read<bone_t>(bones + boneloc);

	bone.x = bo.x + pos.x;
	bone.y = bo.y + pos.y;
	bone.z = bo.z + pos.z;
	return bone;
}
Vector3  SDK::Entity::GetBonePositionByHitBox(int ID)
{
	Vector3 origin = Get_Position();
	if (origin.Empty()) return { 0,0,0 };
	//BoneByHitBox
	uint64_t Model = Read<uint64_t>(this->getAddress() + 0xff0);

	//get studio hdr
	uint64_t StudioHdr = Read<uint64_t>(Model + 0x8);

	//get hitbox array
	uint16_t HitboxCache = Read<uint16_t>(StudioHdr + 0x34);
	uint64_t HitBoxsArray = StudioHdr + ((uint16_t)(HitboxCache & 0xFFFE) << (4 * (HitboxCache & 1)));

	uint16_t IndexCache = Read<uint16_t>(HitBoxsArray + 0x4);
	int HitboxIndex = ((uint16_t)(IndexCache & 0xFFFE) << (4 * (IndexCache & 1)));

	uint16_t Bone = Read<uint16_t>(HitBoxsArray + HitboxIndex + (ID * 0x20));

	if (Bone < 0 || Bone > 255)
		return Vector3();

	//hitpos
	uint64_t BoneArray = Read<uint64_t>(this->getAddress() + Offsets::Misc::Bones);
	uintptr_t Add = BoneArray + Bone * sizeof(matrix3x4_t);
	matrix3x4_t Matrix = Read<matrix3x4_t>(Add);

	return Vector3(Matrix.m_flMatVal[0][3] + origin.x, Matrix.m_flMatVal[1][3] + origin.y, Matrix.m_flMatVal[2][3] + origin.z);
}

SDK::Entity* SDK::Entity::LocalPlayer()
{
	return Read<SDK::Entity*>(sdk.R5Apex + Offsets::Misc::LocalPlayer);
}
SDK::Glow* SDK::Entity::GetGlow()
{
	return Read<SDK::Glow*>(this->getAddress());
}
SDK::Entity::Collision* SDK::Entity::Get_Collision()
{
	return Read<SDK::Entity::Collision*>(this->getAddress() +Offsets::DT_BaseEntity::m_Collision);
}
SDK::Entity::ViewModel* SDK::Entity::Get_ViewModel() {
	return Read<SDK::Entity::ViewModel*>(this->getAddress() + Offsets::DT_Player::m_viewOffsetEntity);
}
SDK::Entity::AnimationData* SDK::Entity::Get_AnimationData() {
	return Read<SDK::Entity::AnimationData*>(this->getAddress() + Offsets::DT_Player::m_animViewEntity);
}
SDK::Entity::Camera* SDK::Entity::Get_Camera() {
	return Read<SDK::Entity::Camera*>(this->getAddress() + Offsets::Misc::Camera);
}
//END

//Collision

Vector3 SDK::Entity::Collision::Get_VecMin() {
	return Read<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecMins);
}
Vector3 SDK::Entity::Collision::Get_VecMax() {
	return Read<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecMaxs);
}
Vector3 SDK::Entity::Collision::Get_vecSpecifiedSurroundingMins() {
	return Read<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecSpecifiedSurroundingMins);
}
Vector3 SDK::Entity::Collision::Get_vecSpecifiedSurroundingMaxs() {
	return Read<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecSpecifiedSurroundingMaxs);
}

int SDK::Entity::Collision::Get_SolidFlags() {
	return Read<int>(this->getAddress() + Offsets::CollisionProperty::m_usSolidFlags);
}
int SDK::Entity::Collision::Get_SolidType() {
	return Read<int>(this->getAddress() + Offsets::CollisionProperty::m_nSolidType);
}
int SDK::Entity::Collision::Get_triggerBloat() {
	return Read<int>(this->getAddress() + Offsets::CollisionProperty::m_triggerBloat);
}
int SDK::Entity::Collision::Get_collisionDetailLevel() {
	return Read<int>(this->getAddress() + Offsets::CollisionProperty::m_collisionDetailLevel);
}
int SDK::Entity::Collision::Get_SurroundType() {
	return Read<int>(this->getAddress() + Offsets::CollisionProperty::m_nSurroundType);
}

void SDK::Entity::Collision::Set_VecMin(Vector3 Min) {
	Write<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecMins, Min);
}
void SDK::Entity::Collision::Set_VecMax(Vector3 Max) {
	Write<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecMaxs, Max);
}
void SDK::Entity::Collision::Set_vecSpecifiedSurroundingMins(Vector3 Min) {
	Write<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecSpecifiedSurroundingMins, Min);
}
void SDK::Entity::Collision::Set_vecSpecifiedSurroundingMaxs(Vector3 Max) {
	Write<Vector3>(this->getAddress() + Offsets::CollisionProperty::m_vecSpecifiedSurroundingMaxs, Max);
}
void SDK::Entity::Collision::Set_SolidFlags(int Flag) {
	Write<int>(this->getAddress() + Offsets::CollisionProperty::m_usSolidFlags, Flag);
}
void SDK::Entity::Collision::Set_SolidType(int Type) {
	Write<int>(this->getAddress() + Offsets::CollisionProperty::m_nSolidType, Type);
}
void SDK::Entity::Collision::Set_triggerBloat(int Trigger) {
	Write<int>(this->getAddress() + Offsets::CollisionProperty::m_triggerBloat, Trigger);
}
void SDK::Entity::Collision::Set_collisionDetailLevel(int Level) {
	Write<int>(this->getAddress() + Offsets::CollisionProperty::m_collisionDetailLevel, Level);
}
void SDK::Entity::Collision::Set_SurroundType(int Type) {
	Write<int>(this->getAddress() + Offsets::CollisionProperty::m_nSurroundType, Type);
}
//End

//Camera
void SDK::Entity::Camera::Set_Fog(bool value)
{
	Write<bool>(this->getAddress() + Offsets::DT_PointCamera::m_bFogEnable, value);
}
void SDK::Entity::Camera::Set_Fov(float FOV)
{
	Write<float>(this->getAddress() + Offsets::DT_PointCamera::m_FOV, FOV);
}
//End

//ViewModel
void SDK::Entity::ViewModel::Set_ViewOffset(int Value) {
	Write<int>(this->getAddress() + Offsets::DT_Player_ViewOffsetEntityData::viewOffsetEntityHandle, Value);

}
void SDK::Entity::ViewModel::Set_StabilizePlayerEyes(int Value) {
	Write<int>(this->getAddress() + Offsets::DT_Player_ViewOffsetEntityData::stabilizePlayerEyeAngles, Value);

}
//End

//Animation
void SDK::Entity::AnimationData::StabilizePlayerEyes(int value) {
	Write<int>(this->getAddress() + Offsets::DT_Player_AnimViewEntityData::animViewEntityStabilizePlayerEyeAngles, value);
}
void SDK::Entity::AnimationData::DrawLocalPlayer(int value) {
	Write<int>(this->getAddress() + Offsets::DT_Player_AnimViewEntityData::animViewEntityDrawPlayer, value);
}
void SDK::Entity::AnimationData::ThirdPersonCamera(int value) {
	Write<int>(this->getAddress() + Offsets::DT_Player_AnimViewEntityData::animViewEntityThirdPersonCameraParity, value);
}
//End