#include "plugin.h"
#include "UnionAfx.h"

extern cppimport UnionCore::TSaveLoadGameInfo UnionCore::SaveLoadGameInfo;

using namespace Common;
using namespace UnionCore;
using namespace Vdfs32;

cexport void Game_Entry() {
}

cexport void Game_Init() {
}

cexport void Game_Exit() {
}

cexport void Game_PreLoop() {
}

cexport void Game_Loop() {
}

cexport void Game_PostLoop() {
}

cexport void Game_MenuLoop() {
}

cexport void Game_SaveBegin() {
}

cexport void Game_SaveEnd() {
}

void LoadBegin() {
}

void LoadEnd() {
}

cexport void Game_LoadBegin_NewGame() {
	LoadBegin();
}

cexport void Game_LoadEnd_NewGame() {
	LoadEnd();
}

cexport void Game_LoadBegin_SaveGame() {
	LoadBegin();
}

cexport void Game_LoadEnd_SaveGame() {
	LoadEnd();
}

cexport void Game_LoadBegin_ChangeLevel() {
	LoadBegin();
}

cexport void Game_LoadEnd_ChangeLevel() {
	LoadEnd();
}

cexport void Game_LoadBegin_Trigger() {
}

cexport void Game_LoadEnd_Trigger() {
}

cexport void Game_Pause() {
}

cexport void Game_Unpause() {
}

cexport void Game_DefineExternals() {
}

cexport void Game_ApplyOptions() {
}

void __fastcall oCMobInter_EndInteraction(oCMobInter* _this, void*, oCNpc*, int);

auto Hook_oCMobInter_EndInteraction = CreateHookByName(&oCMobInter::EndInteraction, &oCMobInter_EndInteraction, Hook_CallPatch);

void __fastcall oCMobInter_EndInteraction(oCMobInter* _this, void* p0, oCNpc* npc, int a) {
	Hook_oCMobInter_EndInteraction(_this, p0, npc, a);

	if (npc->IsAPlayer()) {
		if (_this->sceme == zSTRING("STOVE") || _this->sceme == zSTRING("PAN")) {
			oCItem* rawMeats = npc->inventory2.IsIn(zSTRING("ITFOMUTTONRAW"), 0);

			if (rawMeats != nullptr) {
				if (rawMeats->amount > 1) {
					oCItem* cookedMeats = new oCItem(3843, rawMeats->amount);

					npc->inventory2.Insert(cookedMeats);
					npc->inventory2.Remove(3845, rawMeats->amount);
				}
			}
		}
	}
}