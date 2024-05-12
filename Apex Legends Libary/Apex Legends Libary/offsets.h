#pragma once
#define offset constexpr uint64_t

namespace Offsets {
	namespace Misc {
		offset LocalPlayer = 0x2258688;
		offset GlobalVars = 0x17c4c20;
		offset EntityList = 0x1EA9AE8;
		offset InputSystem = 0x184ba80;
		offset NameList = 0xC78F030;
		offset ClientState = 0x17c4f60;
		offset SignonState = 0x17c500c;
		offset LevelName = 0x17c5120;
		offset ViewRender = 0x73f1978;
		offset ViewMatrix = 0x11a350;
		// add this ur self 
		offset OFF_GLOW_ENABLE = 0x28C;                       //Script_Highlight_GetCurrentContext
		offset OFF_GLOW_THROUGH_WALL = 0x26c;                 //Script_Highlight_SetVisibilityType
		offset OFF_GLOW_FIX = 0x268;
		offset OFF_GLOW_HIGHLIGHT_ID = 0x298;                 //[DT_HighlightSettings].m_highlightServerActiveStates    
		offset OFF_GLOW_HIGHLIGHTS = 0xBB247D0;      //HighlightSettings
		offset Bones = 0x0da0 + 0x48;
        offset Camera = 0xa10;

	}
	namespace C_BaseEntity {
		offset m_ModelName = 0x0030;
		offset m_fFlags = 0x00c8;
		offset m_angAbsRotation = 0x0164;
		offset m_vecAbsOrigin = 0x017c;
		offset m_vecPrevAbsOrigin = 0x02f4;
		offset m_flGravity = 0x0300;
		offset m_rgflCoordinateFrame = 0x07b0;
	}
	namespace DT_BaseEntity {
		offset	moveparent = 0x001c;
		offset	m_parentAttachment = 0x0020;
		offset	m_fEffects = 0x0040;
		offset	m_usableType = 0x0044;
		offset	m_cellX = 0x0048;
		offset	m_cellY = 0x004c;
		offset	m_cellZ = 0x0050;
		offset	m_localOrigin = 0x0054;
		offset	m_nModelIndex = 0x0060;
		offset	m_clrRender = 0x0080;
		offset	m_clIntensity = 0x0084;
		offset	m_bossPlayer = 0x0154;
		offset	m_shieldHealth = 0x01a0;
        offset m_Shield_type = 0x462c;
		offset	m_shieldHealthMax = 0x01a4;
		offset	m_wantsScopeHighlight = 0x02c4;
		offset	m_networkedFlags = 0x02c8;
		offset	m_ignoreParentRotation = 0x02d0;
		offset	m_visibilityFlags = 0x0320;
		offset	m_iTeamNum = 0x0328;
		offset	m_teamMemberIndex = 0x0330;
		offset	m_squadID = 0x0334;
		offset	m_grade = 0x0338;
		offset	m_ignorePredictedTriggerFlags = 0x033c;
		offset	m_passThroughFlags = 0x0344;
		offset	m_passThroughThickness = 0x0348;
		offset	m_passThroughDirection = 0x034c;
		offset	m_bIsSoundCodeControllerValueSet = 0x0364;
		offset	m_flSoundCodeControllerValue = 0x0368;
		offset	m_localAngles = 0x0378;
		offset	m_hOwnerEntity = 0x038c;
		offset	m_bRenderWithViewModels = 0x0390;
		offset	m_nRenderFX = 0x0391;
		offset	m_nRenderMode = 0x03a1;
		offset	m_Collision = 0x03a8;
		offset	m_CollisionGroup = 0x0428;
		offset	m_contents = 0x042c;
		offset	m_collideWithOwner = 0x0430;
		offset	m_iSignifierName = 0x0468;
		offset	m_iName = 0x0471;
		offset	m_scriptNameIndex = 0x0578;
		offset	m_instanceNameIndex = 0x057c;
		offset	m_holdUsePrompt = 0x0600;
		offset	m_pressUsePrompt = 0x0608;
		offset	m_phaseShiftFlags = 0x06a0;
		offset	m_baseTakeDamage = 0x06a4;
		offset	m_invulnerableToDamageCount = 0x06a8;
		offset	m_attachmentLerpStartTime = 0x071c;
		offset	m_attachmentLerpEndTime = 0x0720;
		offset	m_attachmentLerpStartOrigin = 0x0724;
		offset	m_attachmentLerpStartAngles = 0x0730;
		offset	m_parentAttachmentModel = 0x0740;
		offset	m_fadeDist = 0x074c;
		offset	m_dissolveEffectEntityHandle = 0x07f4;
		offset	m_usablePriority = 0x0808;
		offset	m_usableDistanceOverride = 0x080c;
		offset	m_usableFOV = 0x0810;
		offset	m_usePromptSize = 0x0814;
		offset	m_spottedByTeams = 0x0828;
		offset	m_firstChildEntityLink = 0x0920;
		offset	m_firstParentEntityLink = 0x0924;
		offset	m_realmsBitMask = 0x0928;
	}
    namespace DT_Player
    {
        offset m_vecAbsOrigin = 0x0004;
        offset isLocalOriginLocal = 0x0010;
        offset m_fFlags = 0x00c8;
        offset m_hGroundEntity = 0x0314;
        offset m_iHealth = 0x0318;
        offset m_flMaxspeed = 0x031c;
        offset m_jumpPadDebounceExpireTime = 0x0340;
        offset m_iMaxHealth = 0x0460;
        offset m_lifeState = 0x0680;
        offset m_overlayEventParity = 0x1661;
        offset m_inventory = 0x18c8;
        offset m_selectedOffhands = 0x1946;
        offset m_selectedOffhandsPendingHybridAction = 0x1949;
        offset m_titanSoul = 0x19c4;
        offset m_bZooming = 0x1bd1;
        offset m_zoomToggleOnStartTime = 0x1bd4;
        offset m_zoomBaseFrac = 0x1bd8;
        offset m_zoomBaseTime = 0x1bdc;
        offset m_zoomFullStartTime = 0x1be0;
        offset m_currentFramePlayer = 0x2088;
        offset pl = 0x24b0;
        offset m_ammoPoolCapacity = 0x2534;
        offset m_hasBadReputation = 0x2538;
        offset m_hardware = 0x2540;
        offset m_unspoofedHardware = 0x2541;
        offset m_platformUserId = 0x2548;
        offset m_progressionUserId = 0x2550;
        offset m_unSpoofedPlatformUserId = 0x2558;
        offset m_EadpUserId = 0x2560;
        offset m_crossPlayChat = 0x2568;
        offset m_crossPlayChatFriends = 0x2569;
        offset m_crossProgressionMigrated = 0x256a;
        offset m_laserSightColorCustomized = 0x256b;
        offset m_laserSightColor = 0x256c;
        offset m_classModsActive = 0x2578;
        offset m_passives = 0x26b0;
        offset m_bleedoutState = 0x26e0;
        offset m_bleedoutStartTime = 0x26e4;
        offset m_statusEffectsTimedPlayerNV = 0x26e8;
        offset m_statusEffectsEndlessPlayerNV = 0x27d8;
        offset m_damageComboLatestUpdateTime = 0x289c;
        offset m_damageComboStartHealth = 0x28a0;
        offset m_gestureSequences = 0x28a4;
        offset m_gestureStartTimes = 0x28b4;
        offset m_gestureBlendInDuration = 0x28d4;
        offset m_gestureBlendOutDuration = 0x28f4;
        offset m_gestureFadeOutStartTime = 0x2914;
        offset m_gestureFadeOutDuration = 0x2934;
        offset m_gestureAutoKillBitfield = 0x2954;
        offset m_autoSprintForced = 0x2998;
        offset m_fIsSprinting = 0x299c;
        offset m_playerSettingForStickySprintForward = 0x299e;
        offset m_playerSettingForHoldToSprint = 0x299f;
        offset m_lastSprintPressTime = 0x29a0;
        offset m_stickySprintForwardEnableTime = 0x29a4;
        offset m_stickySprintForwardDisableTime = 0x29a8;
        offset m_damageImpulseNoDecelEndTime = 0x29c0;
        offset m_playerVehicles = 0x29cc;
        offset m_playerVehicleCount = 0x29d4;
        offset m_playerVehicleDriven = 0x29d8;
        offset m_playerVehicleUseTime = 0x29dc;
        offset m_duckState = 0x29e0;
        offset m_leanState = 0x29e4;
        offset m_canStand = 0x29e9;
        offset m_StandHullMin = 0x29ec;
        offset m_StandHullMax = 0x29f8;
        offset m_DuckHullMin = 0x2a04;
        offset m_DuckHullMax = 0x2a10;
        offset m_entitySyncingWithMe = 0x2a1c;
        offset m_upDir = 0x2a20;
        offset m_traversalState = 0x2aa4;
        offset m_traversalType = 0x2aa8;
        offset m_traversalForwardDir = 0x2ad4;
        offset m_traversalRefPos = 0x2ae0;
        offset m_traversalYawDelta = 0x2b0c;
        offset m_traversalYawPoseParameter = 0x2b10;
        offset m_wallClimbSetUp = 0x2b28;
        offset m_wallHanging = 0x2b29;
        offset m_grapple = 0x2c40;
        offset m_grappleActive = 0x2cd0;
        offset m_turret = 0x2d14;
        offset m_hViewModels = 0x2d18;
        offset m_viewOffsetEntity = 0x2d28;
        offset m_animViewEntity = 0x2d68;
        offset m_activeZipline = 0x2e58;
        offset m_ziplineValid3pWeaponLayerAnim = 0x2e64;
        offset m_ziplineState = 0x2e68;
        offset m_ziplineGrenadeBeginStationEntity = 0x2f04;
        offset m_ziplineGrenadeBeginStationAttachmentId = 0x2f08;
        offset m_shadowShieldActive = 0x2f30;
        offset m_tempShieldHealth = 0x2f34;
        offset m_extraShieldHealth = 0x2f38;
        offset m_extraShieldTier = 0x2f3c;
        offset m_isPerformingBoostAction = 0x2f5e;
        offset m_lastJumpPadTouched = 0x3058;
        offset m_launchCount = 0x3060;
        offset m_launcherAirControlActive = 0x3064;
        offset m_melee = 0x3190;
        offset m_useCredit = 0x31c8;
        offset m_playerFlags = 0x31d8;
        offset m_hasMic = 0x31e0;
        offset m_inPartyChat = 0x31e1;
        offset m_communicationsAutoBlocked = 0x31e2;
        offset m_playerMoveSpeedScale = 0x31e4;
        offset m_bShouldDrawPlayerWhileUsingViewEntity = 0x3430;
        offset m_iSpawnParity = 0x349c;
        offset m_flDeathTime = 0x3560;
        offset m_ragdollCreationOrigin = 0x3564;
        offset m_ragdollCreationYaw = 0x3570;
        offset m_lastDodgeTime = 0x35b0;
        offset m_timeJetpackHeightActivateCheckPassed = 0x35d8;
        offset m_grappleHook = 0x3678;
        offset m_petTitan = 0x367c;
        offset m_xp = 0x36a4;
        offset m_skill_mu = 0x36ac;
        offset m_bHasMatchAdminRole = 0x36b0;
        offset m_ubEFNoInterpParity = 0x3ff8;
        offset m_hColorCorrectionCtrl = 0x3ffc;
        offset m_title = 0x4020;
        offset m_Shared = 0x4350;
        offset m_pilotClassIndex = 0x43a4;
        offset m_playerScriptNetDataGlobal = 0x4630;
        offset m_helmetType = 0x4638;
        offset m_armorType = 0x463c;
        offset m_controllerModeActive = 0x4644;
        offset m_skydiveForwardPoseValueTarget = 0x4668;
        offset m_skydiveSidePoseValueTarget = 0x4674;
        offset m_skydiveState = 0x469c;
        offset m_skydiveDiveAngle = 0x46b4;
        offset m_skydiveIsDiving = 0x46b8;
        offset m_skydiveSpeed = 0x46bc;
        offset m_skydiveStrafeAngle = 0x46c0;
        offset m_skydivePlayerPitch = 0x46d4;
        offset m_skydivePlayerYaw = 0x46d8;
        offset m_skydiveFromSkywardLaunch = 0x4715;
        offset m_skydiveScriptInputOverride = 0x4718;
        offset m_skydiveContraintPostion = 0x471c;
        offset m_skydiveContraintRadius = 0x4728;
        offset m_skywardLaunchState = 0x472c;
        offset m_skywardLaunchSlowStartTime = 0x4740;
        offset m_skywardLaunchSlowEndTime = 0x4744;
        offset m_skywardLaunchFastEndTime = 0x4748;
        offset m_skywardLaunchEndTime = 0x4750;
        offset m_skywardLaunchSlowSpeed = 0x4758;
        offset m_skywardLaunchFastSpeed = 0x475c;
        offset m_skywardOffset = 0x4760;
        offset m_skywardLaunchInterrupted = 0x4770;
        offset m_skywardLaunchFollowing = 0x4771;
        offset m_skywardObstacleAvoidanceEndPos = 0x4774;
        offset m_armoredLeapAirPos = 0x4784;
        offset m_armoredLeapEndPos = 0x4790;
        offset m_armoredLeapType = 0x479c;
        offset m_armoredLeapPhase = 0x47a0;
        offset m_armoredLeapStartTime = 0x47a4;
        offset m_dragReviveState = 0x4810;
        offset m_dragReviveOutroStartTime = 0x4814;
        offset m_reviveTarget = 0x4818;
    }
    namespace CollisionProperty {
        offset m_vecMins = 0x0010;
        offset m_vecMaxs = 0x001c;
        offset m_usSolidFlags = 0x0028;
        offset m_nSolidType = 0x002c;
        offset m_triggerBloat = 0x002d;
        offset m_collisionDetailLevel = 0x002e;
        offset m_nSurroundType = 0x003c;
        offset m_vecSpecifiedSurroundingMins = 0x0048;
        offset m_vecSpecifiedSurroundingMaxs = 0x0054;
    }
    namespace DT_Player_ViewOffsetEntityData
    {
        offset viewOffsetEntityHandle = 0x0008;
        offset lerpInDuration = 0x000c;
        offset lerpOutDuration = 0x0010;
        offset stabilizePlayerEyeAngles = 0x0014;
    }
    namespace DT_Player_AnimViewEntityData
    {
        offset animViewEntityAngleLerpInDuration = 0x0004;
        offset animViewEntityOriginLerpInDuration = 0x0008;
        offset animViewEntityLerpOutDuration = 0x000c;
        offset animViewEntityStabilizePlayerEyeAngles = 0x0010;
        offset animViewEntityThirdPersonCameraParity = 0x0014;
        offset animViewEntityThirdPersonCameraAttachment = 0x0018;
        offset animViewEntityNumThirdPersonCameraAttachments = 0x0020;
        offset animViewEntityThirdPersonCameraVisibilityChecks = 0x0024;
        offset animViewEntityDrawPlayer = 0x0025;
        offset fovTarget = 0x0028;
        offset fovSmoothTime = 0x002c;
        offset animViewEntityParity = 0x0038;
    }
    namespace DT_WeaponInventory
    {
        offset weapons = 0x0008;
        offset offhandWeapons = 0x0038;
        offset activeWeapons = 0x0064;
    }
    namespace DT_Player_LocalData
    {
        offset bcc_localdata = 0x0000;
        offset m_weaponGettingSwitchedOut = 0x0008;
        offset m_showActiveWeapon3p = 0x0010;
        offset m_vecViewOffset_x = 0x0034;
        offset m_vecViewOffset_y = 0x0038;
        offset m_vecViewOffset_z = 0x003c;
        offset m_cloakEndTime = 0x01cc;
        offset m_cloakFadeInEndTime = 0x01d0;
        offset m_cloakFadeOutStartTime = 0x01d4;
        offset m_cloakFadeInDuration = 0x01d8;
        offset m_cloakFlickerAmount = 0x01dc;
        offset m_cloakFlickerEndTime = 0x01e0;
        offset m_networkedFlags = 0x02c8;
        offset m_deathVelocity = 0x0350;
        offset m_minimapData = 0x0848;
        offset m_nameVisibilityFlags = 0x0898;
        offset m_bIsPlayerOverheating = 0x1890;
        offset m_playerOverheatValue = 0x1894;
        offset m_timeLastGeneratedPlayerOverheat = 0x1898;
        offset m_lastFiredTime = 0x18a0;
        offset m_lastFiredWeapon = 0x18a4;
        offset m_raiseFromMeleeEndTime = 0x18a8;
        offset m_sharedEnergyCount = 0x18ac;
        offset m_sharedEnergyTotal = 0x18b0;
        offset m_sharedEnergyLockoutThreshold = 0x18b4;
        offset m_lastSharedEnergyRegenTime = 0x18b8;
        offset m_sharedEnergyRegenRate = 0x18bc;
        offset m_sharedEnergyRegenDelay = 0x18c0;
        offset m_lastSharedEnergyTakeTime = 0x18c4;
        offset m_selectedWeapons = 0x1930;
        offset m_latestPrimaryWeapons = 0x1934;
        offset m_latestPrimaryWeaponsIndexZeroOrOne = 0x193c;
        offset m_latestNonOffhandWeapons = 0x1944;
        offset m_lastCycleSlot = 0x194c;
        offset m_weaponPermission = 0x1954;
        offset m_weaponDelayEnableTime = 0x1958;
        offset m_weaponDisabledInScript = 0x195c;
        offset m_weaponDisabledFlags = 0x1972;
        offset m_weaponInventorySlotLockedFlags = 0x1974;
        offset m_weaponTypeDisabledFlags = 0x1978;
        offset m_weaponTypeDisabledRefCount = 0x197c;
        offset m_allowHudSelectionWhileWeaponsDisabled = 0x1986;
        offset m_weaponAmmoRegenDisabled = 0x1987;
        offset m_weaponAmmoRegenDisabledRefCount = 0x1988;
        offset m_akimboState = 0x198c;
        offset m_akimboShouldAltFire = 0x198d;
        offset m_hudInfo_visibilityTestAlwaysPasses = 0x198e;
        offset m_contextAction = 0x19a0;
        offset m_phaseShiftType = 0x19cc;
        offset m_phaseShiftTimeStart = 0x19d0;
        offset m_phaseShiftTimeEnd = 0x19d4;
        offset m_targetInfoPingValue = 0x1b60;
    }
    namespace DT_PointCamera
    {
        offset m_FOV = 0x09c0;
        offset m_bFogEnable = 0x09e8;
        offset m_bActive = 0x09e9;
    }
}