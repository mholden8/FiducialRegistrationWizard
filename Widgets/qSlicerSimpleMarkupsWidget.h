/*==============================================================================

  Program: 3D Slicer

  Copyright (c) Kitware Inc.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

==============================================================================*/

#ifndef __qSlicerSimpleMarkupsWidget_h
#define __qSlicerSimpleMarkupsWidget_h

// Qt includes
#include "qSlicerWidget.h"

#include "qMRMLUtils.h"

// FooBar Widgets includes
#include "qSlicerFiducialRegistrationWizardModuleWidgetsExport.h"
#include "ui_qSlicerSimpleMarkupsWidget.h"

#include "vtkSlicerFiducialRegistrationWizardLogic.h"

#include "vtkMRMLSelectionNode.h"
#include "vtkMRMLInteractionNode.h"

#include "vtkMRMLMarkupsFiducialNode.h"
#include "vtkSlicerMarkupsLogic.h"


class qSlicerSimpleMarkupsWidgetPrivate;

/// \ingroup Slicer_QtModules_CreateModels
class Q_SLICER_MODULE_FIDUCIALREGISTRATIONWIZARD_WIDGETS_EXPORT 
qSlicerSimpleMarkupsWidget : public qSlicerWidget
{
  Q_OBJECT
public:
  typedef qSlicerWidget Superclass;
  qSlicerSimpleMarkupsWidget(QWidget *parent=0);
  virtual ~qSlicerSimpleMarkupsWidget();

  static qSlicerSimpleMarkupsWidget* New( vtkSlicerMarkupsLogic* newMarkupsLogic );

  vtkSlicerMarkupsLogic* MarkupsLogic;

  vtkMRMLNode* GetCurrentNode();
  void SetCurrentNode( vtkMRMLNode* currentNode );
  void SetNodeBaseName( const char* newNodeBaseName );

  void GetNodeColor( double rgb[3] );
  void SetNodeColor( double rgb[3] );
  void SetDefaultNodeColor( double rgb[3] );


public slots:

  void highlightNthFiducial( int n );

protected slots:

  void onColorButtonChanged( QColor );
  void onVisibilityButtonClicked();
  void onLockButtonClicked();
  void onDeleteButtonClicked();
  void onPlaceButtonClicked();
  void onActiveButtonClicked();

  void onMarkupsFiducialNodeChanged();
  void onMarkupsFiducialNodeAdded( vtkMRMLNode* );
  void onMarkupsFiducialTableContextMenu(const QPoint& position);

  void onMarkupsFiducialEdited( int row, int column );

  void updateWidget();

signals:

  void markupsFiducialNodeChanged();
  void markupsFiducialActivated();
  void markupsFiducialPlaceModeChanged();
  void updateFinished();

protected:
  QScopedPointer<qSlicerSimpleMarkupsWidgetPrivate> d_ptr;

  virtual void setup();
  virtual void enter();

  void ConnectInteractionAndSelectionNodes();

  double DefaultNodeColor[3];

private:
  Q_DECLARE_PRIVATE(qSlicerSimpleMarkupsWidget);
  Q_DISABLE_COPY(qSlicerSimpleMarkupsWidget);

};

#endif
