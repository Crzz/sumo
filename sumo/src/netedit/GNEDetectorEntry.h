/****************************************************************************/
/// @file    GNEDetectorEntry.h
/// @author  Pablo Alvarez Lopez
/// @date    Nov 2015
/// @version $Id$
///
///
/****************************************************************************/
// SUMO, Simulation of Urban MObility; see http://sumo.dlr.de/
// Copyright (C) 2001-2017 DLR (http://www.dlr.de/) and contributors
/****************************************************************************/
//
//   This file is part of SUMO.
//   SUMO is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as published by
//   the Free Software Foundation; either version 3 of the License, or
//   (at your option) any later version.
//
/****************************************************************************/
#ifndef GNEDetectorEntry_h
#define GNEDetectorEntry_h


// ===========================================================================
// included modules
// ===========================================================================
#ifdef _MSC_VER
#include <windows_config.h>
#else
#include <config.h>
#endif

#include "GNEDetector.h"

// ===========================================================================
// class declarations
// ===========================================================================
class GNEDetectorE3;

// ===========================================================================
// class definitions
// ===========================================================================
/**
 * @class GNEDetectorEntry
 * Class for detector of type Entry
 */
class GNEDetectorEntry  : public GNEDetector {
public:
    /**@brief Constructor
     * @param[in] viewNet pointer to GNEViewNet of this additional element belongs
     * @param[in] parent pointer to GNEDetectorE3 of this Entry belongs
     * @param[in] lane Lane of this StoppingPlace belongs
     * @param[in] pos position of the detector on the lane
     */
    GNEDetectorEntry(GNEViewNet* viewNet, GNEDetectorE3* parent, GNELane* lane, double pos);

    /// @brief destructor
    ~GNEDetectorEntry();

    /**@brief writte additional element into a xml file
     * @param[in] device device in which write parameters of additional element
     * @param[in] volatileOptionsEnabled flag to indicate that additionals are being saved with volatile options enabled 
     */
    void writeAdditional(OutputDevice& device, bool volatileOptionsEnabled) const;

    /// @brief get E3 Detector parent
    GNEDetectorE3* getE3Parent() const;

    /// @brief update pre-computed geometry information called by E3 parent
    void updateGeometryByParent();

    /// @name Functions related with geometry of element
    /// @{
    /**@brief change the position of the element geometry without saving in undoList
     * @param[in] newPosition new position of geometry
     * @note should't be called in drawGL(...) functions to avoid smoothness issues
     */
    void moveGeometry(const Position &newPosition);

    /**@brief commit geometry changes in the attributes of an element after use of moveGeometry(...)
     * @param[in] oldPos the old position of additional
     * @param[in] undoList The undoList on which to register changes
     */
    void commmitGeometryMoving(const Position& oldPos, GNEUndoList* undoList);

    /// @brief update pre-computed geometry information
    void updateGeometry();

    /// @brief Returns position of additional in view
    Position getPositionInView() const;
    /// @}

    /// @name inherited from GUIGlObject
    /// @{
    /**@brief Draws the object
     * @param[in] s The settings for the current view (may influence drawing)
     * @see GUIGlObject::drawGL
     */
    void drawGL(const GUIVisualizationSettings& s) const;
    /// @}

    /// @name inherited from GNEAttributeCarrier
    /// @{
    /* @brief method for getting the Attribute of an XML key
     * @param[in] key The attribute key
     * @return string with the value associated to key
     */
    std::string getAttribute(SumoXMLAttr key) const;

    /* @brief method for setting the attribute and letting the object perform additional changes
     * @param[in] key The attribute key
     * @param[in] value The new value
     * @param[in] undoList The undoList on which to register changes
     */
    void setAttribute(SumoXMLAttr key, const std::string& value, GNEUndoList* undoList);

    /* @brief method for checking if the key and their correspond attribute are valids
     * @param[in] key The attribute key
     * @param[in] value The value asociated to key key
     * @return true if the value is valid, false in other case
     */
    bool isValid(SumoXMLAttr key, const std::string& value);
    /// @}

private:
    /// @brief pointer to E3 parent
    GNEDetectorE3* myE3Parent;

    /// @brief variable to save detectorEntry icon
    static GUIGlID detectorEntryGlID;

    /// @brief check if detectorEntry icon was inicilalizated
    static bool detectorEntryInitialized;

    /// @brief set attribute after validation
    void setAttribute(SumoXMLAttr key, const std::string& value);

    /// @brief Invalidated copy constructor.
    GNEDetectorEntry(const GNEDetectorEntry&);

    /// @brief Invalidated assignment operator.
    GNEDetectorEntry& operator=(const GNEDetectorEntry&);

    /// @brief Invalidated get filename
    const std::string &getFilename() const;

    /// @brief Invalidated set frequency
    int getFrequency() const;

    /// @brief Invalidated set filename
    void setFrequency(double freq);

    /// @brief Invalidated
    void setFilename(const std::string &filename);
};

#endif

/****************************************************************************/
