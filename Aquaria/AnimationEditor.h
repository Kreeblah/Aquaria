#ifndef ANIMATION_EDITOR_H
#define ANIMATION_EDITOR_H

#include "../BBGE/SkeletalSprite.h"
#include "StateManager.h"
#include <list>

class DebugFont;
class BitmapText;

class KeyframeWidget : public Quad
{
public:
	KeyframeWidget(int key);
	float t;
	int key;
	static KeyframeWidget *movingWidget;
	BitmapText *b;

	void shiftLeft();
	void shiftRight();
protected:
	void onUpdate(float dt);
};


class AnimationEditor : public StateObject
{
public:
	AnimationEditor();
	void applyState();
	void removeState();
	void update(float dt);

	void prevKey();
	void nextKey();
	void newKey();
	void deleteKey();
	void animate();
	void stop();
	void animateOrStop();
	void newAnim();

	void lmbu();
	void lmbd();
	void rmbu();
	void rmbd();
	void mmbd();

	void constrainMouse();

	void reorderKeys();

	void saveFile();
	void loadFile();

	void copyKey();
	void pasteKey();

	void nextAnim();
	void prevAnim();

	void quit();

	void load();
	void loadSkin();

	void copy();
	void paste();

	void cloneBoneAhead();

	void zoomIn();
	void zoomOut();

	void resetScaleOrSave();

	void clearRot();
	void clearPos();
	void flipRot();
	void cycleLerpType();

	void toggleHideBone();

	void undo();
	void redo();
	void pushUndo();
	void clearUndoHistory();

	void applyTranslation();
	void applyRotation();

	void moveNextWidgets(float dt);

	std::list<SkeletalSprite> undoHistory;

	int undoEntry;

	int currentKey;

	int rotOffset;

	SkeletalSprite *editSprite;
	Bone *editingBone;
	int boneEdit;
	DebugFont *text, *text2;

	void goToTitle();

	SkeletalKeyframe copyBuffer;

	std::string editingFile;

	std::vector<KeyframeWidget*> keyframeWidgets;

	void action(int id, int state, int source);

	void rebuildKeyframeWidgets();

	Vector cursorOffset;

	void moveBoneStripPoint(const Vector &mov);

	void editStripKey();
	void toggleMouseSelection();
	void selectPrevBone();
	void selectNextBone();

	bool mouseSelection;

	SkeletalKeyframe buffer;

	bool editingStrip;
	int selectedStripPoint;

	void reverseAnim();

	void toggleRenderBorders();
	void updateRenderBorders();
	bool renderBorders;
	void updateEditingBone();
	void showAllBones();
	void incrTimelineUnit();
	void decrTimelineUnit();
	void updateTimelineUnit();
	void incrTimelineGrid();
	void decrTimelineGrid();
	void updateTimelineGrid();
	DebugFont *gridsize, *unitsize;
};


#endif
