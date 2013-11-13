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

// FooBar Widgets includes
#include "qSlicerFiducialRegistrationWizardModuleWidgetsExport.h"
#include "ui_qSlicerSimpleMarkupsWidget.h"

#include "vtkSlicerFiducialRegistrationWizardLogic.h"

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

protected slots:

  void onMarkupsFiducialTableClicked();
  void onMarkupsFiducialNodeChanged();

  void updateWidget();

protected:
  QScopedPointer<qSlicerSimpleMarkupsWidgetPrivate> d_ptr;

  virtual void setup();
  virtual void enter();

private:
  Q_DECLARE_PRIVATE(qSlicerSimpleMarkupsWidget);
  Q_DISABLE_COPY(qSlicerSimpleMarkupsWidget);

};

#endif