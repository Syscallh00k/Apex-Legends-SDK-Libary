#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
// Add Drver, Vector Math
#include "offsets.h"
#include "Vector_Math.h"
#include "memory.h"

class SDK {
public:
	
	std::uint64_t R5Apex = NULL;
	Vector2 DisplaySize = {0,0};
	class Universal{
	public:
		
	};
	class Game {
	public:
		class Get {
		public:
			std::uint64_t getAddress();
		private:
			std::uintptr_t Address;
		};
		class Script : public Get {
		public:
			std::string GetName();
			std::string getModelName();
			std::string getSignifierName();
		};
		class WorldToScreen : public Script {
		public:
			Vector3 W2S(Vector3 Position);
		};
	};
	class Glow : public Game::Get {
	public:
		void SetGlow(int GlowEnabled, int GlowThroughWall, int HighlightID);
		void DisableGlow();
	};
	class Entity : public SDK::Game::WorldToScreen
	{
	public:
		class Collision : public SDK::Game::Get{
		public:
			Vector3 Get_VecMin();
			Vector3 Get_VecMax();
			Vector3 Get_vecSpecifiedSurroundingMins();
			Vector3 Get_vecSpecifiedSurroundingMaxs();

			int Get_SolidFlags();
			int Get_SolidType();
			int Get_triggerBloat();
			int Get_collisionDetailLevel();
			int Get_SurroundType();

			void Set_VecMin(Vector3 Min);
			void Set_VecMax(Vector3 Max);
			void Set_vecSpecifiedSurroundingMins(Vector3 Min);
			void Set_vecSpecifiedSurroundingMaxs(Vector3 Max);

			void Set_SolidFlags(int Flag);
			void Set_SolidType(int Type);
			void Set_triggerBloat(int Trigger);
			void Set_collisionDetailLevel(int Level);
			void Set_SurroundType(int Type);
	

		};
		class ViewModel : public SDK::Game::Get {
		public:
			void Set_ViewOffset(int Value);
			void Set_StabilizePlayerEyes(int Value);
		};
		class AnimationData : public SDK::Game::Get {
		public:
			void StabilizePlayerEyes(int value);
			void DrawLocalPlayer(int value);
			void ThirdPersonCamera(int value);
		};
		class Camera : public SDK::Game::Get {
		public:
			void Set_Fov(float FOV);
			void Set_Fog(bool value);
		};
		void Update();
		int Get_Current_shield();
		int Get_Max_shield();
		int Get_shield_type();
		int Get_Network_Flags();
		void Set_Network_Flags(int Network_Flag);
		void ignoreParentRotation(int Rotation);
		int Get_TeamNum();
		void Set_PassthroughThickness(int thickness);
		bool Get_Alive();
		bool Get_IsLocalPlayer();
		float Get_Height();
		float Get_Width();
		Vector3 Get_Position();
		Vector3 getBonePos(int ID);
		Vector3 GetBonePositionByHitBox(int ID);
		float GetDistance();
		bool Get_IsPlayer();
		int Current_Health();
		
		// vars
		int Health;
		int Shield;
		int Max_Shield;
		int Shield_Type;
		bool Is_Alive;
		bool IsPlayer;
		bool IsLocalPlayer;
		float Distance;
		float Width;
		float Height;
		Vector3 Feet_Position;
		Vector3 Head_Position;
		std::vector<Entity*> List;

		//ptr
		Entity* LocalPlayer();
		Glow* GetGlow();
		Collision* Get_Collision();
		ViewModel* Get_ViewModel();
		AnimationData* Get_AnimationData();
		Camera* Get_Camera();
	};
};
SDK sdk;
